FROM ubuntu-poco-git

WORKDIR /root
ARG USELESS=1
RUN cd Coursework-test/writer && mkdir build && cd build && cmake .. && make && cd ../../..

ENV LD_LIBRARY_PATH=/usr/local/lib
EXPOSE 8080
ENTRYPOINT ./Coursework-test/writer/build/writer