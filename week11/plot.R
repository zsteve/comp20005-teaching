#!/usr/bin/Rscript
library(ggplot2)
eul <- read.table('output_euler', header = T)
mod_eul <- read.table('output_mod_euler', header = T)
rk4 <- read.table('output_rk4', header = T)
ggplot() + geom_point(aes(x = 1:nrow(eul), y = eul$x)) + geom_point(aes(x = 1:nrow(mod_eul), y = mod_eul$x), color = 'red') + geom_point(aes(x = 1:nrow(rk4), y = rk4$x), color = 'blue')
