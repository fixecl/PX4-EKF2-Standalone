#geo atmosphere world_magnetic_model 3in1 from PX4

set(GEO_SRCS)

list(APPEND GEO_SRCS
		geo.cpp
		geo.h
		atmosphere.cpp
		atmosphere.h
		geo_mag_declination.cpp
		geo_mag_declination.h
		geo_magnetic_tables.hpp
		)

add_library(geo
		${GEO_SRCS}
		)


