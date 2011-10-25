zz<-read.csv("hw3stats.csv",head=TRUE,sep=",")

y1<-zz[c(1:10),]
y2<-zz[c(13:22),]
y3<-zz[c(25:34),]
y4<-zz[c(37:46),]
y5<-zz[c(49:58),]

print(y1)
print(y2)
print(y3)
print(y4)
print(y5)

io_aov<-aov(zz$io ~ zz$group)
cpu_aov<-aov(zz$cpu ~ zz$group)
mix_aov<-aov(zz$mix ~ zz$group)
totalexe_aov<-aov(zz$totalexe ~ zz$group)
totalscript_aov<-aov(zz$totalscript ~ zz$group)
summary(io_aov)

sd1io<-sd(y1$io)
sd1cpu<-sd(y1$cpu)
sd1mix<-sd(y1$mix)
mean1io<-mean(y1$io)
mean1cpu<-mean(y1$cpu)
mean1mix<-mean(y1$mix)

sd2io<-sd(y2$io)
sd2cpu<-sd(y2$cpu)
sd2mix<-sd(y2$mix)
mean2io<-mean(y2$io)
mean2cpu<-mean(y2$cpu)
mean2mix<-mean(y2$mix)

sd3io<-sd(y3$io)
sd3cpu<-sd(y3$cpu)
sd3mix<-sd(y3$mix)
mean3io<-mean(y3$io)
mean3cpu<-mean(y3$cpu)
mean3mix<-mean(y3$mix)

sd4io<-sd(y4$io)
sd4cpu<-sd(y4$cpu)
sd4mix<-sd(y4$mix)
mean4io<-mean(y4$io)
mean4cpu<-mean(y4$cpu)
mean4mix<-mean(y4$mix)

sd5io<-sd(y5$io)
sd5cpu<-sd(y5$cpu)
sd5mix<-sd(y5$mix)
mean5io<-mean(y5$io)
mean5cpu<-mean(y5$cpu)
mean5mix<-mean(y5$mix)
# summary(cpu_aov)
# summary(mix_aov)
# summary(totalexe_aov)
# summary(totalscript_aov)

print(sd1io)
print(sd1cpu)
print(sd1mix)
print(mean1io)
print(mean1cpu)
print(mean1mix)


print(sd2io)
print(sd2cpu)
print(sd2mix)
print(mean2io)
print(mean2cpu)
print(mean2mix)

print(sd3io)
print(sd3cpu)
print(sd3mix)
print(mean3io)
print(mean3cpu)
print(mean3mix)

print(sd4io)
print(sd4cpu)
print(sd4mix)
print(mean4io)
print(mean4cpu)
print(mean4mix)

print(sd5io)
print(sd5cpu)
print(sd5mix)
print(mean5io)
print(mean5cpu)
print(mean5mix)

sdcpu=c(sd1cpu,sd2cpu,sd3cpu,sd4cpu,sd5cpu)
sdio=c(sd1io,sd2io,sd3io,sd4io,sd5io)
sdmix=c(sd1mix,sd2mix,sd3mix,sd4mix,sd5mix)
meancpu=c(mean1cpu,mean2cpu,mean3cpu,mean4cpu,mean5cpu)
meanio=c(mean1io,mean2io,mean3io,mean4io,mean5io)
meanmix=c(mean1mix,mean2mix,mean3mix,mean4mix,mean5mix)
colors=c("red","green","blue","purple","black")
opts=c(y1$cpu,y2$cpu,y3$cpu,y4$cpu,y5$cpu)
cpus=c(y1$cpu,y2$cpu,y3$cpu,y4$cpu,y5$cpu)
ios=c(y1$io,y2$io,y3$io,y4$io,y5$io)
mixes=c(y1$mix,y2$mix,y3$mix,y4$mix,y5$mix)
print(cpus)
print(range(cpus))

legenddata=c("NR_SCHED_QUEUE=32","NR_SCHED_QUEUE=64","USER_QUANTUM=800","USER_QUANTUM=25","BALANCE_TIMEOUT=20")

par(mar=c(10,4,4,2) + 0.1)   
par(xpd=TRUE) 
plot(y1$cpu,ylim=range(cpus),main="CPU Times (In sample order)",col="red",xlab="Iterations",ylab="CPU Time (seconds)", type="l")
lines(c(1:10),y2$cpu,type="l",col="green")
lines(c(1:10),y3$cpu,type="l",col="blue")
lines(c(1:10),y4$cpu,type="l",col="purple")
lines(c(1:10),y5$cpu,type="l")
legend(1,min(range(cpus)-2.7),legenddata,col=colors,lty=c(1,1,1,1,1))

plot(sort(y1$cpu),ylim=range(cpus),main="CPU Times Sorted",col="red",ylab="CPU Time (seconds)", type="l")
lines(c(1:10),sort(y2$cpu),type="l",col="green")
lines(c(1:10),sort(y3$cpu),type="l",col="blue")
lines(c(1:10),sort(y4$cpu),type="l",col="purple")
lines(c(1:10),sort(y5$cpu),type="l")
legend(1,min(range(cpus)-2.7),legenddata,col=colors,lty=c(1,1,1,1,1))

##############################                           
plot(y1$io,ylim=range(ios),col="red",type="l",main="IO Times (In sample order)",xlab="Iterations",ylab="IO Time (seconds)")
lines(c(1:10),y2$io,type="l",col="green")
lines(c(1:10),y3$io,type="l",col="blue")
lines(c(1:10),y4$io,type="l",col="purple")
lines(c(1:10),y5$io,type="l")
legend(1,min(range(ios)-13),legenddata,col=colors,lty=c(1,1,1,1,1))

plot(sort(y1$io),ylim=range(ios),col="red",type="l",main="IO Times Sorted",ylab="IO Time (seconds)")
lines(c(1:10),sort(y2$io),type="l",col="green")
lines(c(1:10),sort(y3$io),type="l",col="blue")
lines(c(1:10),sort(y4$io),type="l",col="purple")
lines(c(1:10),sort(y5$io),type="l")
legend(1,min(range(ios)-13),legenddata,col=colors,lty=c(1,1,1,1,1))

#############################

plot(y1$mix,ylim=range(mixes),col="red",type="l",main="Mix Times (In sample order)",xlab="Iterations",ylab="Mix Time (seconds)")
lines(c(1:10),y2$mix,type="l",col="green")
lines(c(1:10),y3$mix,type="l",col="blue")
lines(c(1:10),y4$mix,type="l",col="purple")
lines(c(1:10),y5$mix,type="l")
legend(1,min(range(mixes)-2.5),legenddata,col=colors,lty=c(1,1,1,1,1))


plot(sort(y1$mix),ylim=range(mixes),col="red",type="l",main="Mix Times Sorted",ylab="Mix Time (seconds)")
lines(c(1:10),sort(y2$mix),type="l",col="green")
lines(c(1:10),sort(y3$mix),type="l",col="blue")
lines(c(1:10),sort(y4$mix),type="l",col="purple")
lines(c(1:10),sort(y5$mix),type="l")
legend(1,min(range(mixes)-2.5),legenddata,col=colors,lty=c(1,1,1,1,1))
#############################
barplot(sdcpu,main="SD CPU",col=colors,legend=legenddata)
barplot(sdio,main="SD IO",col=colors,legend=legenddata)
barplot(sdmix,main="SD MIX",col=colors,legend=legenddata)
barplot(meancpu,main="MEAN CPU",col=colors,legend=legenddata)
barplot(meanio,main="MEAN IO",col=colors,legend=legenddata)
barplot(meanmix,main="MEAN MIX",col=colors,legend=legenddata)
      
cpumeans=c(mean(y1$cpu),mean(y2$cpu),mean(y3$cpu),mean(y4$cpu),mean(y5$cpu))

plot(sort(cpumeans),type="l")