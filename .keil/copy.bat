cd %~dp0
SET GenFolder=..\target\

if not exist %GenFolder% (
	md ..\target
)
copy .\Objects\%1 ..\target\%1 /y