FROM python:3.8-alpine
RUN ["apk", "update"]

RUN ["apk", "add", "gcc", "g++"]
RUN ["apk", "add", "cmake"]
RUN ["apk", "add", "make"]

RUN ["echo", "dependency installation finished"]

COPY . "/tmp/flask"
WORKDIR "/tmp/flask/build"

RUN ["cmake", "-DCMAKE_INSTALL_PREFIX=/opt/techprog", ".."]
RUN ["make"]

RUN ["mkdir", "/opt/techprog"]
RUN ["cp", "../lib/", "/opt/techprog/lib/", "-r"]
RUN ["ln", "../bin/C", "/bin/C"]

RUN ["addgroup", "tp2022user"]
RUN ["adduser", "-D", "-h", "/home/tp2022user", "-s", "/bin/sh", "-G", "tp2022user", "tp2022user"]

WORKDIR "/home/tp2022user"

RUN ["cp", "/tmp/flask/app.py", "."]
RUN ["chown", "tp2022user:tp2022user", "./app.py"]

RUN ["cp", "./app.py", "/opt/techprog/"]
RUN ["chmod", "644", "/opt/techprog/app.py"]

USER "tp2022user"

ENV PATH = "${PATH}:/home/tp2022user/.local/bin"
RUN ["pip", "install", "-r", "/tmp/flask/requirements.txt"]


CMD ["python3", "/opt/techprog/app.py", "--host", "0.0.0.0", "--port", "8089"]
