/**
 * Copy from PX4
 * build/px4_sitl_default/uORB/topics/estimator_aid_source1d.h
 */

#ifndef FLEXFC_ESTIMATOR_AID_SOURCE_H
#define FLEXFC_ESTIMATOR_AID_SOURCE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


struct estimator_aid_source1d_s {
    uint64_t timestamp;
    uint64_t timestamp_sample;
    uint64_t time_last_fuse;
    uint32_t device_id;
    float observation;
    float observation_variance;
    float innovation;
    float innovation_variance;
    float test_ratio;
    uint8_t estimator_instance;
    bool innovation_rejected;
    bool fused;
    uint8_t _padding0[5]; // required for logger
};

struct estimator_aid_source2d_s {
    uint64_t timestamp;
    uint64_t timestamp_sample;
    uint64_t time_last_fuse;
    uint32_t device_id;
    float observation[2];
    float observation_variance[2];
    float innovation[2];
    float innovation_variance[2];
    float test_ratio[2];
    uint8_t estimator_instance;
    bool innovation_rejected;
    bool fused;
    uint8_t _padding0[1]; // required for logger
};

struct estimator_aid_source3d_s {
    uint64_t timestamp;
    uint64_t timestamp_sample;
    uint64_t time_last_fuse;
    uint32_t device_id;
    float observation[3];
    float observation_variance[3];
    float innovation[3];
    float innovation_variance[3];
    float test_ratio[3];
    uint8_t estimator_instance;
    bool innovation_rejected;
    bool fused;
    uint8_t _padding0[5]; // required for logger
};


#ifdef __cplusplus
}
#endif

#endif //FLEXFC_ESTIMATOR_AID_SOURCE_H
