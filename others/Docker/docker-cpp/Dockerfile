FROM gcc:7.3.0
COPY . /code

WORKDIR /code 
RUN g++ hello_docker.cpp -o test.out 
CMD ["./test.out"]