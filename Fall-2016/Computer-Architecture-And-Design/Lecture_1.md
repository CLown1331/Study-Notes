#####27th September 2016

###Computer Architecture

Computer architecture is about selecting and interconnecting hardware components to create a computer
that meet functional perfomance of cost goals.

--

Computer Architecture refers to instruction set design and implementation.

* The Term Instruction Set Architecture(ISA) refers to the actual programmer visible instruction set. It
  serves as the boundary of softaware and hardware.
 
* Implementation of machine has two components:
 * Organization - includes the high level aspects of computer design. Such as memory system, bus structure.
 
 * Hardware - refers to the specifics of a machine, including the detailed logic design and packaging technology 
   of the machine.

--
  
###Task of a Computer Designer

* Determine the attributes that are important for the new machine.
* Design a machine to maximize to performance while staying within cost constraints and power constraints.
* Some important design aspects:
 * Instruction set design
 * Functional organization
 * Logic design
 * Implementation

* Must be aware of important trends in both implementation technology and the use of computers.
 
 
--

###Measuring and Reporting Performance

* Response time - the time between the start and the completion of an event. It is also referred to as execution time.
* Throughput - the total amount of work done in a given time.

####X is faster than Y:

* X is faster than Y is used to mean that the response/execution time is lower on X than to Y for the given task. Thus,
  (Execution time y) / (Execution time x) = n

* Since execution time is reciprocal to performance, the following relationship holds,
  n = (Execution time y) / (Execution time x) = (Performance x) / (Performance y)
  
  
  
--

###Throughput of X is 1.3 higher than Y:

The throughput of X is 1.3 times higher than Y means that the number of tasks completed per unit time on machine X
is 1.3 times the number completed on Y.



--

###Choosing programs to evaluate performance

There are five levels of programs used to evaluate performance. They are listed below in decreasing order of accuracy
of prediction.

* Real-time application - compiler, word, Photoshop etc.
* Modified application
* Kernels.
* Toy benchmarks
* Synthetic benchmark.
