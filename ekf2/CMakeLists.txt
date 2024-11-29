# EKF2 from PX4 ekf2 30e763b6780061d70a14894e3e8b06e6a656f9b8
# add_subdirectory(Utility)

message(STATUS "EKF2: Very lightweight Estimation & Control Library")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(EKF2_SYMFORCE_GEN "ekf2 generate symforce output" OFF)

# Symforce code generation TODO:fixme
execute_process(
    COMMAND ${PYTHON_EXECUTABLE} -m symforce.symbolic
    RESULT_VARIABLE PYTHON_SYMFORCE_EXIT_CODE
    OUTPUT_QUIET
)

# for now only provide symforce target helper if derivation.py generation isn't default
if((NOT CONFIG_EKF2_MAGNETOMETER) OR (NOT CONFIG_EKF2_WIND))
	set(EKF2_SYMFORCE_GEN ON)
endif()

set(EKF_DERIVATION_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/EKF/python/ekf_derivation)

set(EKF_GENERATED_FILES ${EKF_DERIVATION_SRC_DIR}/generated/state.h)
set(EKF_GENERATED_DERIVATION_INCLUDE_PATH "${EKF_DERIVATION_SRC_DIR}/..")

if(EKF2_SYMFORCE_GEN AND (${PYTHON_SYMFORCE_EXIT_CODE} EQUAL 0))

	# regenerate default in tree
	add_custom_command(
		OUTPUT
			${EKF_DERIVATION_SRC_DIR}/generated/predict_covariance.h
			${EKF_DERIVATION_SRC_DIR}/generated/state.h
		COMMAND
			${PYTHON_EXECUTABLE} ${EKF_DERIVATION_SRC_DIR}/derivation.py
		DEPENDS
			${EKF_DERIVATION_SRC_DIR}/derivation.py
			${EKF_DERIVATION_SRC_DIR}/utils/derivation_utils.py

		WORKING_DIRECTORY ${EKF_DERIVATION_SRC_DIR}
		COMMENT "Symforce code generation (default)"
		USES_TERMINAL
	)

	# generate to build directory
	set(EKF_DERIVATION_DST_DIR ${CMAKE_CURRENT_BINARY_DIR}/ekf_derivation)
	file(MAKE_DIRECTORY ${EKF_DERIVATION_DST_DIR})

	set(EKF_GENERATED_FILES ${EKF_DERIVATION_DST_DIR}/generated/state.h)
	set(EKF_GENERATED_DERIVATION_INCLUDE_PATH ${CMAKE_CURRENT_BINARY_DIR})

	set(SYMFORCE_ARGS)

	if(NOT CONFIG_EKF2_MAGNETOMETER)
		message(STATUS "ekf2: symforce disabling mag")
		list(APPEND SYMFORCE_ARGS "--disable_mag")
	endif()

	if(NOT CONFIG_EKF2_WIND)
		message(STATUS "ekf2: symforce disabling wind")
		list(APPEND SYMFORCE_ARGS "--disable_wind")
	endif()

	add_custom_command(
		OUTPUT
			${EKF_DERIVATION_DST_DIR}/generated/predict_covariance.h
			${EKF_DERIVATION_DST_DIR}/generated/state.h
		COMMAND
			${PYTHON_EXECUTABLE} ${EKF_DERIVATION_SRC_DIR}/derivation.py ${SYMFORCE_ARGS}
		DEPENDS
			${EKF_DERIVATION_SRC_DIR}/derivation.py
			${EKF_DERIVATION_SRC_DIR}/utils/derivation_utils.py

		WORKING_DIRECTORY ${EKF_DERIVATION_DST_DIR}
		COMMENT "Symforce code generation"
		USES_TERMINAL
	)



	add_custom_target(ekf2_symforce_generate
		DEPENDS
			${EKF_DERIVATION_SRC_DIR}/generated/predict_covariance.h
			${EKF_DERIVATION_DST_DIR}/generated/predict_covariance.h
	)
endif()

set(EKF_LIBS)

add_subdirectory(EKF)


if(BUILD_TESTING)
	add_subdirectory(test)
endif()
