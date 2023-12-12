#!/bin/bash
OUT_FILE=performance.md
URL=http://0.0.0.0:9003
echo --------------------- > $OUT_FILE
echo -- WITH CACHE >> $OUT_FILE
echo --------------------- >> $OUT_FILE
wrk -s get_cache.lua $URL >> $OUT_FILE
echo --------------------- >> $OUT_FILE
echo -- NO CACHE >> $OUT_FILE
echo --------------------- >> $OUT_FILE
wrk -s get_no_cache.lua $URL >> $OUT_FILE
