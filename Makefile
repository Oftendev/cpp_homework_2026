CPP = g++
CPPFLAGS = -Wall -std=c++11

TARGET = program
OBJS = main.o QuadEquation.o Student.o Email.o Teacher.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp QuadEquation.h Student.h Email.h Teacher.h
	$(CPP) $(CPPFLAGS) -c main.cpp

QuadEquation.o: QuadEquation.cpp QuadEquation.h
	$(CPP) $(CPPFLAGS) -c QuadEquation.cpp

Student.o: Student.cpp Student.h QuadEquation.h
	$(CPP) $(CPPFLAGS) -c Student.cpp

Email.o: Email.cpp Email.h QuadEquation.h Student.h
	$(CPP) $(CPPFLAGS) -c Email.cpp

Teacher.o: Teacher.cpp Teacher.h Email.h Student.h
	$(CPP) $(CPPFLAGS) -c Teacher.cpp

run: $(TARGET)
	./$(TARGET)