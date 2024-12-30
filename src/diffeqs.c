double diffeq_harmonic_oscillator(double x, double y[], int i) {
    if (i == 0) {
        return y[1];
    }
    if (i == 1) {
        return -y[0] - 0.4*y[1];
    }
    else return 0;
}