---------------------
-- WITH CACHE
---------------------
Running 10s test @ http://0.0.0.0:9003
  2 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     4.93ms   14.51ms 130.33ms   90.88%
    Req/Sec    10.44k     2.94k   14.61k    72.00%
  207807 requests in 10.00s, 57.87MB read
Requests/sec:  20777.47
Transfer/sec:      5.79MB
---------------------
-- NO CACHE
---------------------
Running 10s test @ http://0.0.0.0:9003
  2 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    19.16ms   36.04ms 243.26ms   84.72%
    Req/Sec     6.97k     4.00k   13.55k    54.84%
  134842 requests in 10.01s, 38.39MB read
Requests/sec:  13474.84
Transfer/sec:      3.84MB
