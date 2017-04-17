d= read.csv(file="fixed_edge.csv", header=TRUE, sep=",")

l=lm(log10(d$time) ~ log10(d$n) )
summary(l)
with(d,plot(log10(d$n),log10(d$time)))
abline(l)

plotdata = cbind(log10(d$time), log10(d$n), fitted(l) )
colnames(plotdata) = c("logtime", "logn", "pred" )
write.csv(plotdata, "fix_edge_lin_regression.csv",row.names=FALSE)