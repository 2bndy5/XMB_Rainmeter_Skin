____________________measures___________________

[MeasureCurrentLibraries]
measure=string
dynamicVariables=1
string="#Steamappsdir1# *#Steamappsdir2#"
updateDivider=4
ifMatchMode=1
ifmatch=^none\s.*$
IfMatchAction=[!setOption Library1 group notValid][!updateMeter Library1]
ifMatch2=^.*\*none$
ifMatchAction2=[!setOption Library2 group notvalid][!updateMeter Library2]

[MeasureRootPath]
measure=plugin
plugin=fileview
dynamicVariables=1
Path="#SteamAppsDIR#"
ShowDotDot=0
type=filecount
sorttype=date
sortdatetype=modified
SortAscending=0
count=12
showhidden=0
showfolder=0
extensions=acf
ifBelowValue=13
ifBelowAction=[!hideMeterGroup scrollPages]
ifAboveValue=13
ifAboveAction=[!showMeterGroup scrollPages]
finishAction=[!update][!updateMeasure MeasureCurrentLibraries]
onchangeaction=[!UpdatemeasureGroup gamecount][!Enablemeasuregroup "webparser[measuregameitems]"][!showmetergroup "item[measuregameitems]"][!setoptiongroup item[measuregameitems] updatedivider 1][!updatemetergroup item[measuregameitems]]

[measuregameitems]
measure=calc
formula=MeasureRootPath > 11 ? 12 : MeasureRootPath
dynamicvariables=1
updatedivider=-1
group=gamecount

[measureName1]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=1

[measureName2]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=2

[measureName3]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=3

[measureName4]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=4

[measureName5]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=5

[measureName6]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=6

[measureName7]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=7

[measureName8]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=8

[measureName9]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=9

[measureName10]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=10

[measureName11]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=11

[measureName12]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=12

[MeasureGameParser1]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName1]"
updaterate=2
Regexp=(?siU)(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10 | webparser9 | webparser8 | webparser7 | webparser1 | webparser2 | webparser3 | webparser4 | webparser5 | webparser6
disabled=1

[MeasureAppID1]
measure=plugin
plugin=webparser
url=[MeasureGameParser1]
stringindex=1
errorstring=0

[MeasureAppIcon1]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID1]/header.jpg
download=1
downloadfile=[MeasureAppID1].jpg
disabled=1
FinishAction=[!setoption #CurrentSection# updatedivider -1][!disablemeasure #CurrentSection#][!updatemeter 1]

[MeasureAppName1]
measure=plugin
plugin=webparser
url=[MeasureGameParser1]
stringindex=2

[MeasureAppDIR1]
measure=plugin
plugin=webparser
url=[MeasureGameParser1]
stringindex=3

[MeasureAppSize1]
measure=plugin
plugin=webparser
url=[MeasureGameParser1]
stringindex=4
ifcondition=MeasureAppSize1 > 1073741824
iftrueaction=!setvariable Sizecalc1 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc1 "/1048576,1] MB"

[MeasureGameParser2]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName2]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10 | webparser9 | webparser8 | webparser7 | webparser2 | webparser3 | webparser4 | webparser5 | webparser6
disabled=1

[MeasureAppID2]
measure=plugin
plugin=webparser
url=[MeasureGameParser2]
stringindex=1

[MeasureAppIcon2]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID2]/header.jpg
download=1
downloadfile=[MeasureAppID2].jpg
disabled=1
FinishAction=[!setoption Measureappicon2 updatedivider -1][!disablemeasure Measureappicon2][!updatemeter 2]

[MeasureAppName2]
measure=plugin
plugin=webparser
url=[MeasureGameParser2]
stringindex=2

[MeasureAppDIR2]
measure=plugin
plugin=webparser
url=[MeasureGameParser2]
stringindex=3

[MeasureAppSize2]
measure=plugin
plugin=webparser
url=[MeasureGameParser2]
stringindex=4
ifcondition=MeasureAppSize2 > 1073741824
iftrueaction=!setvariable Sizecalc2 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc2 "/1048576,1] MB"

[MeasureGameParser3]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName3]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10 | webparser9 | webparser8 | webparser7 | webparser3 | webparser4 | webparser5 | webparser6
disabled=1

[MeasureAppID3]
measure=plugin
plugin=webparser
url=[MeasureGameParser3]
stringindex=1

[MeasureAppIcon3]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID3]/header.jpg
download=1
downloadfile=[MeasureAppID3].jpg
disabled=1
FinishAction=[!setoption Measureappicon3 updatedivider -1][!disablemeasure Measureappicon3][!updatemeter 3]

[MeasureAppName3]
measure=plugin
plugin=webparser
url=[MeasureGameParser3]
stringindex=2

[MeasureAppDIR3]
measure=plugin
plugin=webparser
url=[MeasureGameParser3]
stringindex=3

[MeasureAppSize3]
measure=plugin
plugin=webparser
url=[MeasureGameParser3]
stringindex=4
ifcondition=MeasureAppSize3 > 1073741824
iftrueaction=!setvariable Sizecalc3 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc3 "/1048576,1] MB"

[MeasureGameParser4]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName4]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10 | webparser9 | webparser8 | webparser7 | webparser4 | webparser5 | webparser6
disabled=1

[MeasureAppID4]
measure=plugin
plugin=webparser
url=[MeasureGameParser4]
stringindex=1

[MeasureAppIcon4]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID4]/header.jpg
download=1
downloadfile=[MeasureAppID4].jpg
disabled=1
FinishAction=[!setoption Measureappicon4 updatedivider -1][!disablemeasure Measureappicon4][!updatemeter 4]

[MeasureAppName4]
measure=plugin
plugin=webparser
url=[MeasureGameParser4]
stringindex=2

[MeasureAppDIR4]
measure=plugin
plugin=webparser
url=[MeasureGameParser4]
stringindex=3

[MeasureAppSize4]
measure=plugin
plugin=webparser
url=[MeasureGameParser4]
stringindex=4
ifcondition=MeasureAppSize4 > 1073741824
iftrueaction=!setvariable Sizecalc4 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc4 "/1048576,1] MB"

[MeasureGameParser5]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName5]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10 | webparser9 | webparser8 | webparser7 | webparser5 | webparser6
disabled=1

[MeasureAppID5]
measure=plugin
plugin=webparser
url=[MeasureGameParser5]
stringindex=1

[MeasureAppIcon5]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID5]/header.jpg
download=1
downloadfile=[MeasureAppID5].jpg
disabled=1
FinishAction=[!setoption Measureappicon5 updatedivider -1][!disablemeasure Measureappicon5][!updatemeter 5]

[MeasureAppName5]
measure=plugin
plugin=webparser
url=[MeasureGameParser5]
stringindex=2

[MeasureAppDIR5]
measure=plugin
plugin=webparser
url=[MeasureGameParser5]
stringindex=3

[MeasureAppSize5]
measure=plugin
plugin=webparser
url=[MeasureGameParser5]
stringindex=4
ifcondition=MeasureAppSize5 > 1073741824
iftrueaction=!setvariable Sizecalc5 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc5 "/1048576,1] MB"

[MeasureGameParser6]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName6]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10 | webparser9 | webparser8 | webparser7 | webparser6
disabled=1

[MeasureAppID6]
measure=plugin
plugin=webparser
url=[MeasureGameParser6]
stringindex=1

[MeasureAppIcon6]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID6]/header.jpg
download=1
downloadfile=[MeasureAppID6].jpg
disabled=1
FinishAction=[!setoption Measureappicon6 updatedivider -1][!disablemeasure Measureappicon6][!updatemeter 6]

[MeasureAppName6]
measure=plugin
plugin=webparser
url=[MeasureGameParser6]
stringindex=2

[MeasureAppDIR6]
measure=plugin
plugin=webparser
url=[MeasureGameParser6]
stringindex=3

[MeasureAppSize6]
measure=plugin
plugin=webparser
url=[MeasureGameParser6]
stringindex=4
ifcondition=MeasureAppSize6 > 1073741824
iftrueaction=!setvariable Sizecalc6 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc6 "/1048576,1] MB"

[MeasureGameParser7]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName7]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10 | webparser9 | webparser8 | webparser7
disabled=1

[MeasureAppID7]
measure=plugin
plugin=webparser
url=[MeasureGameParser7]
stringindex=1

[MeasureAppIcon7]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID7]/header.jpg
download=1
downloadfile=[MeasureAppID7].jpg
disabled=1
FinishAction=[!setoption Measureappicon7 updatedivider -1][!disablemeasure Measureappicon7][!updatemeter 7]

[MeasureAppName7]
measure=plugin
plugin=webparser
url=[MeasureGameParser7]
stringindex=2

[MeasureAppDIR7]
measure=plugin
plugin=webparser
url=[MeasureGameParser7]
stringindex=3

[MeasureAppSize7]
measure=plugin
plugin=webparser
url=[MeasureGameParser7]
stringindex=4
ifcondition=MeasureAppSize7 > 1073741824
iftrueaction=!setvariable Sizecalc7 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc7 "/1048576,1] MB"

[MeasureGameParser8]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName8]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10 | webparser9 | webparser8
disabled=1

[MeasureAppID8]
measure=plugin
plugin=webparser
url=[MeasureGameParser8]
stringindex=1

[MeasureAppIcon8]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID8]/header.jpg
download=1
downloadfile=[MeasureAppID8].jpg
disabled=1
FinishAction=[!setoption Measureappicon8 updatedivider -1][!disablemeasure Measureappicon8][!updatemeter 8]

[MeasureAppName8]
measure=plugin
plugin=webparser
url=[MeasureGameParser8]
stringindex=2

[MeasureAppDIR8]
measure=plugin
plugin=webparser
url=[MeasureGameParser8]
stringindex=3

[MeasureAppSize8]
measure=plugin
plugin=webparser
url=[MeasureGameParser8]
stringindex=4
ifcondition=MeasureAppSize8 > 1073741824
iftrueaction=!setvariable Sizecalc8 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc8 "/1048576,1] MB"

[MeasureGameParser9]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName9]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10 | webparser9
disabled=1

[MeasureAppID9]
measure=plugin
plugin=webparser
url=[MeasureGameParser9]
stringindex=1

[MeasureAppIcon9]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID9]/header.jpg
download=1
downloadfile=[MeasureAppID9].jpg
disabled=1
FinishAction=[!setoption Measureappicon9 updatedivider -1][!disablemeasure Measureappicon9][!updatemeter 9]

[MeasureAppName9]
measure=plugin
plugin=webparser
url=[MeasureGameParser9]
stringindex=2

[MeasureAppDIR9]
measure=plugin
plugin=webparser
url=[MeasureGameParser9]
stringindex=3

[MeasureAppSize9]
measure=plugin
plugin=webparser
url=[MeasureGameParser9]
stringindex=4
ifcondition=MeasureAppSize9 > 1073741824
iftrueaction=!setvariable Sizecalc9 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc9 "/1048576,1] MB"

[MeasureGameParser10]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName10]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11 | webparser10
disabled=1

[MeasureAppID10]
measure=plugin
plugin=webparser
url=[MeasureGameParser10]
stringindex=1

[MeasureAppIcon10]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID10]/header.jpg
download=1
downloadfile=[MeasureAppID10].jpg
disabled=1
FinishAction=[!setoption Measureappicon10 updatedivider -1][!disablemeasure Measureappicon10][!updatemeter 10]

[MeasureAppName10]
measure=plugin
plugin=webparser
url=[MeasureGameParser10]
stringindex=2

[MeasureAppDIR10]
measure=plugin
plugin=webparser
url=[MeasureGameParser10]
stringindex=3

[MeasureAppSize10]
measure=plugin
plugin=webparser
url=[MeasureGameParser10]
stringindex=4
ifcondition=MeasureAppSize10 > 1073741824
iftrueaction=!setvariable Sizecalc10 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc10 "/1048576,1] MB"

[MeasureGameParser11]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName11]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12 | webparser11
disabled=1

[MeasureAppID11]
measure=plugin
plugin=webparser
url=[MeasureGameParser11]
stringindex=1

[MeasureAppIcon11]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID11]/header.jpg
download=1
downloadfile=[MeasureAppID11].jpg
disabled=1
FinishAction=[!setoption Measureappicon11 updatedivider -1][!disablemeasure Measureappicon11][!updatemeter 11]

[MeasureAppName11]
measure=plugin
plugin=webparser
url=[MeasureGameParser11]
stringindex=2

[MeasureAppDIR11]
measure=plugin
plugin=webparser
url=[MeasureGameParser11]
stringindex=3

[MeasureAppSize11]
measure=plugin
plugin=webparser
url=[MeasureGameParser11]
stringindex=4
ifcondition=MeasureAppSize11 > 1073741824
iftrueaction=!setvariable Sizecalc11 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc11 "/1048576,1] MB"

[MeasureGameParser12]
measure=plugin
plugin=webparser
dynamicvariables=1
url="file://[&measureName12]"
updaterate=2
Regexp=(?siU)\n\{.*"appid"\s*"(?'appid'.*)".*"name"\s*"(?'Name'.*)".*"installdir"\s*"(?'InstallDir'.*)".*"sizeondisk".*"(?'Size'.*)"
group=webparser12
disabled=1

[MeasureAppID12]
measure=plugin
plugin=webparser
url=[MeasureGameParser12]
stringindex=1

[MeasureAppIcon12]
measure=plugin
plugin=webparser
dynamicvariables=1
updatedivider=-1
updaterate=2
url=http://cdn.akamai.steamstatic.com/steam/apps/[&MeasureAppID12]/header.jpg
download=1
downloadfile=[MeasureAppID12].jpg
disabled=1
FinishAction=[!setoption Measureappicon12 updatedivider -1][!disablemeasure Measureappicon12][!updatemeter 12]

[MeasureAppName12]
measure=plugin
plugin=webparser
url=[MeasureGameParser12]
stringindex=2

[MeasureAppDIR12]
measure=plugin
plugin=webparser
url=[MeasureGameParser12]
stringindex=3

[MeasureAppSize12]
measure=plugin
plugin=webparser
url=[MeasureGameParser12]
stringindex=4
ifcondition=MeasureAppSize12 > 1073741824
iftrueaction=!setvariable Sizecalc12 "/1073741824,2] GB"
iffalseaction=!setvariable Sizecalc12 "/1048576,1] MB"

[MeasureImageFiles]
Measure=Script
ScriptFile=#@#imageExistances.lua
dynamicVariables=1
updateDivider=4
File1="#CURRENTPATH#downloadfile\[MeasureAppID1].jpg"
File2="#CURRENTPATH#downloadfile\[MeasureAppID2].jpg"
File3="#CURRENTPATH#downloadfile\[MeasureAppID3].jpg"
File4="#CURRENTPATH#downloadfile\[MeasureAppID4].jpg"
File5="#CURRENTPATH#downloadfile\[MeasureAppID5].jpg"
File6="#CURRENTPATH#downloadfile\[MeasureAppID6].jpg"
File7="#CURRENTPATH#downloadfile\[MeasureAppID7].jpg"
File8="#CURRENTPATH#downloadfile\[MeasureAppID8].jpg"
File9="#CURRENTPATH#downloadfile\[MeasureAppID9].jpg"
File10="#CURRENTPATH#downloadfile\[MeasureAppID10].jpg"
File11="#CURRENTPATH#downloadfile\[MeasureAppID11].jpg"
File12="#CURRENTPATH#downloadfile\[MeasureAppID12].jpg"
imagesPath="#CURRENTPATH#downloadfile\"