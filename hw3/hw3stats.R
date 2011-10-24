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

print(y1$cpu)
opts=c(y1$cpu,y2$cpu,y3$cpu,y4$cpu,y5$cpu)
j<-0
print(opts[j:(j+10)])
# for(i in 1:5){
# 	print(i)
# 	print(opts[i])
# 	print("\n")
# 	plot(c(1:10),opts[j:(j+10)])
# 	lines(c(1:10),opts[j:(j+10)],type="p")
# 	j<-j+10
# 	print(j)
# 
# }

plot(c(1:10),y1$cpu,col="red",main="CPU Times",xlab="Iterations",ylab="CPU Time (seconds)", type="l")
lines(c(1:10),y2$cpu,type="l",col="green")
lines(c(1:10),y3$cpu,type="l",col="blue")
lines(c(1:10),y4$cpu,type="l",col="purple")
lines(c(1:10),y5$cpu,type="l")
                           
plot(c(1:10),y1$io,col="red")
lines(c(1:10),y2$io,type="p",col="green")
lines(c(1:10),y3$io,type="p",col="blue")
lines(c(1:10),y4$io,type="p",col="purple")
lines(c(1:10),y5$io,type="p")

plot(c(1:10),y1$mix,col="red")
lines(c(1:10),y2$mix,type="p",col="green")
lines(c(1:10),y3$mix,type="p",col="blue")
lines(c(1:10),y4$mix,type="p",col="purple")
lines(c(1:10),y5$mix,type="p")

