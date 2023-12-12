FROM python
RUN apt-get update -y
RUN apt-get install -y libmariadb-dev
WORKDIR /root
RUN git clone -b lab-04 https://github.com/alexander-rodionov/Coursework-test.git
WORKDIR /root/Coursework-test/test
RUN /root/Coursework-test/test/makevenv.sh
ENTRYPOINT ["/root/Coursework-test/test/venv/bin/python3"]
