#!/usr/bin/bash
wget -P https://github.com/aissap/alx-low_level_programming/blob/master/0x18-dynamic_libraries/libgiga.so
export LD_PRELOAD=/tpm/libgiga.so 
