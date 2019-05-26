#!/bin/bash
TIME=100;STEP=0.1;./mod_euler 0.1 100 > output_mod_euler && ./rk4 0.1 100 > output_rk4 && ./euler 0.1 100 > output_euler && ./plot.R 
