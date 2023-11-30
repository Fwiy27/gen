FROM gcc:latest
WORKDIR /usr/src/myapp
COPY . /usr/src/myapp
COPY /Classes/Name/Names /usr/src/myapp/Classes/Name/Names

RUN make build

CMD ["./main"]

LABEL Name=dockertest Version=0.0.1
