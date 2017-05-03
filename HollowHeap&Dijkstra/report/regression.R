d= read.csv(file="fix_vertex.csv", header=TRUE, sep=",")

l=lm(log10(d$time) ~ log10(d$m) )
summary(l)
with(d,plot(log10(d$m),log10(d$time)))
abline(l)

plotdata = cbind(log10(d$time), log10(d$m), fitted(l) )
colnames(plotdata) = c("logtime", "logn", "pred" )
write.csv(plotdata, "fix_vertex_lin_regression.csv",row.names=FALSE)
