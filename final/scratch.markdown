#Scheduler
* Mach uses a time sharing scheduler (mainly)
* Each thread is assigned a priority between 0-31
* Blocking or long running threads have their priority decreased
* Threads have three priorities (base, current, max)
* Along with the time sharing policy next had an incomplete implementation for interactive scheduling and a non recommended fixed scheduling policy.

#Mutual Exclusion
* Next through Mach uses a c style mutex lock for memory protection

		`mutex_lock(m);
		count += 1;	
		mutex_unlock(m);`
		
* There was also a framework called Mach Kit which provided a form of mutual exclusion
"Define various kinds of locks that can be useful for protecting critical sections of code in drivers and multithreaded applications"



http://www.mactech.com/articles/mactech/Vol.13/13.05/WebObjectsOverview/index.html

http://www.cilinder.be/docs/next/NeXTStep/3.3/nd/

http://download.info.apple.com/Apple_Support_Area/Apple_Software_Updates/MultiCountry/Enterprise/nextstep/floppyimages/