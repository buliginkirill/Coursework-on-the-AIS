FROM ubuntu-poco

WORKDIR /root
RUN git clone https://github.com/buliginkirill/Coursework-on-the-AIS.git
RUN cd Coursework-on-the-AIS/chat && mkdir build && cd build && cmake .. && make && cd ../../..

ENV LD_LIBRARY_PATH=/usr/local/lib
EXPOSE 8080
ENTRYPOINT ./Coursework-on-the-AIS/chat/build/chat
