@SET /P command=Command : 
@SET /P classpath=Class Path : 
java -Dfile.encoding=UTF-8 -jar packet-tool.jar %command% %classpath% MCUF_
pause