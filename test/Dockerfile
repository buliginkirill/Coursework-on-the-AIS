FROM python
RUN apt-get update -y
RUN apt-get install -y libmariadb-dev
WORKDIR /root
RUN git clone -b main https://github.com/buliginkirill/Coursework-on-the-AIS
WORKDIR /root/Coursework-test/test
RUN /root/Coursework-test/test/makevenv.sh
ENTRYPOINT ["/root/Coursework-test/test/venv/bin/python3"]
