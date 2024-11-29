#include <iostream>
#include "ekf2/EKF/ekf.h"

int main() {
    Ekf *ekf = new Ekf();
    ekf->init(0);

    return 0;
}
