CFLAGS = -I include -std=c++0x
LIBDIR = 
LNFLAGS = -lcppunit -ldl
OBJECTS = 
OBJECTLIST = $(addprefix bin/,${OBJECTS})
VPATH = src test

TESTOBJECTS = $(filter-out bin/main.o,$(OBJECTLIST))
TESTOBJECTS += 

GXX = g++


all: test sched

test: $(TESTOBJECTS)
	${GXX} -L $(LIBDIR) -o $@ $^ $(LNFLAGS)

sched: $(OBJECTLIST)
	${GXX} -L $(LIBDIR) -o $@ $^ $(LNFLAGS) 


bin/%.o : %.cc
	${GXX} $(CFLAGS) -c $^ ${LIBDIR} -o $@

clean:
	rm -Rf $(OBJECTLIST) $(TESTOBJECTS) *~ sched test