if (exist("n")==0 || n<0) n=0 #initialization

plot [0:40] [-0.2:0.35] sprintf("data-%d", n) with lines title sprintf("data-%d", n)

if (n<3999) pause 0.001; n=n+1; \
          reread        # reread this scrpit

n=-1
#end of script
