output: driver.o drivers.o passenger.o passengers.o ride.o rides.o main.o luxury.o group.o economy.o basic.o
	g++ driver.o drivers.o passenger.o passengers.o ride.o rides.o main.o luxury.o group.o economy.o basic.o -o output

main.o: main.cpp drivers.h rides.h passengers.h
	g++ -c main.cpp

driver.o: driver.cpp driver.h
	g++ -c driver.cpp

drivers.o: drivers.cpp drivers.h
	g++ -c drivers.cpp

passenger.o: passenger.cpp passenger.h
	g++ -c passenger.cpp

passengers.o: passengers.cpp passengers.h
	g++ -c passengers.cpp

ride.o: ride.cpp ride.h
	g++ -c ride.cpp

rides.o: rides.cpp rides.h
	g++ -c rides.cpp

economy.o: economy.cpp economy.h
	g++ -c economy.cpp

basic.o: basic.cpp basic.h
	g++ -c basic.cpp

group.o: group.cpp group.h
	g++ -c group.cpp

luxury.o: luxury.cpp luxury.h
	g++ -c luxury.cpp

clean:
	rm *.o output

