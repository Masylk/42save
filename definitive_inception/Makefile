NAME = Inception

all: reload

stop:
	@ docker-compose -f srcs/docker-compose.yml down

clean:	stop
	@ docker-compose -f srcs/docker-compose.yml down --volumes --rmi all

prune: clean
	@ docker system prune -f

reload: 
	@ docker-compose -f srcs/docker-compose.yml up --build -d

.PHONY: stop clean prune reload all
