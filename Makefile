CFLAGS = -I include -std=c++0x
LIBDIR =
LNFLAGS = -lcppunit -ldl
OBJECTS = Course.o CourseCont.o CourseSched.o Exceptions.o InputWrap.o main.o Options.o Output.o Rater.o Scheduler.o
OBJECTLIST = $(addprefix bin/,${OBJECTS})
VPATH = src test

TESTOBJECTS = $(filter-out bin/main.o,$(OBJECTLIST))
TESTOBJECTS += bin/tests.o bin/course_testfixture.o bin/coursecont_testfixture.o bin/coursesched_testfixture.o bin/inputwrap_testfixture.o bin/options_testfixture.o bin/output_testfixture.o bin/rater_testfixture.o bin/scheduler_testfixture.o

GXX = g++

$(shell mkdir -p bin)

all: tests sched

tests: $(TESTOBJECTS)
	${GXX} -o $@ $^ $(LNFLAGS)

sched: $(OBJECTLIST)
	${GXX} -o $@ $^ $(LNFLAGS) 


bin/%.o : %.cc
	${GXX} $(CFLAGS) -c $^ -o $@

clean:
	rm -Rf bin *~ sched tests