NAME = Inception

all: reload

stop:
	@ docker-compose -f srcs/docker-compose.yaml down

clean:	stop
	@ docker-compose -f srcs/docker-compose.yaml down --volumes --rmi all

reload: 
	@ docker-compose -f srcs/docker-compose.yaml up --build -d

.PHONY: stop clean reload all
