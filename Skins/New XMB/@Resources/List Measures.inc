[MeasurePreviousFolder]
Measure=String
DynamicVariables=1
String=[MeasureRootPath]
RegExpSubstitute=1
Substitute="(?i)^(.*\\)(\w|\d|\s).*$":"\1"
updateDivider=-1
onUpdateAction=[!setVariable PreviousFolder [MeasurePreviousFolder]]

[MeasureCountFile]
measure=plugin
plugin=fileview
path=[MeasureRootPath]
type=filecount

[MeasureCountFolder]
measure=plugin
plugin=fileview
path=[MeasureRootPath]
type=Foldercount

[measureitemposition]
measure=calc
dynamicvariables=1
formula=(MeasureCountFolder + MeasureCountFile) >= 7 ? 0 : ((MeasureCountFolder + MeasureCountFile) = 6 ? 1 :((MeasureCountFolder + MeasureCountFile) = 5 ? 2 : ((MeasureCountFolder + MeasureCountFile) = 4 ? 3 : ((MeasureCountFolder + MeasureCountFile) <= 3 ? 3 : 0))))
ifconditionmode=1
ifcondition=(MeasureCountFolder + MeasureCountFile) <= 3
iftrueaction=[!movemeter 35 ([measureitemposition]*90) icon1][!movemeter 35 (([measureitemposition]+1)*90) icon2][!movemeter 35 (([measureitemposition]+2)*90) icon3][!movemeter 35 (([measureitemposition]+3)*90) icon4][!redraw]
ifCondition2=(MeasureCountFolder + MeasureCountFile) = 5
iftrueaction2=[!movemeter 35 ([measureitemposition]*90) icon1][!movemeter 35 (([measureitemposition]+1)*90) icon2][!movemeter 35 (([measureitemposition]+2)*90) icon3][!movemeter 35 (([measureitemposition]+3)*90) icon4][!movemeter 35 (([measureitemposition]+4)*90) icon5][!redraw]
ifCondition3=(MeasureCountFolder + MeasureCountFile) = 6
iftrueaction3=[!movemeter 35 ([measureitemposition]*90) icon1][!movemeter 35 (([measureitemposition]+1)*90) icon2][!movemeter 35 (([measureitemposition]+2)*90) icon3][!movemeter 35 (([measureitemposition]+3)*90) icon4][!movemeter 35 (([measureitemposition]+4)*90) icon5][!movemeter 35 (([measureitemposition]+5)*90) icon6][!redraw]
ifCondition4=(MeasureCountFolder + MeasureCountFile) >= 7
iftrueaction4=[!movemeter 35 ([measureitemposition]*90) icon1][!movemeter 35 (([measureitemposition]+1)*90) icon2][!movemeter 35 (([measureitemposition]+2)*90) icon3][!movemeter 35 (([measureitemposition]+3)*90) icon4][!movemeter 35 (([measureitemposition]+4)*90) icon5][!movemeter 35 (([measureitemposition]+5)*90) icon6][!movemeter 35 (([measureitemposition]+6)*90) icon7][!redraw]

[measureName1]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filename
index=1
group=fileviewplugin
substitute="":"none"
ifmatch=none
ifmatchaction=[!hidemetergroup item1]
ifNotmatchAction=[!showmetergroup item1]

[measuresize1]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filesize
index=1
substitute="":"0"
ifconditionmode=1
ifcondition=measuresize1 = 0
iftrueaction=[!setoption filesize1 text "[measuredate1]"][!setOption icon1 MeterStyle "IconStyle | Folder1"][!setOption icon1B MeterStyle "IconStyle | Folder1"]
iffalseaction=[!setoption filesize1 text "[measuresize1:/1048576,2] Mb"][!setOption icon1 MeterStyle "IconStyle | File1"][!setOption icon1B MeterStyle "IconStyle | File1"]
group=fileviewplugin

[measuredate1]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=Filedate
datetype=created
index=1
group=fileviewplugin

[measurePath1]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=1
group=fileviewplugin

[measureName2]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filename
index=2
group=fileviewplugin
substitute="":"none"
ifmatch=none
ifmatchaction=[!hidemetergroup item2]
ifNotmatchAction=[!showmetergroup item2]

[measuresize2]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filesize
index=2
substitute="":"0"
ifconditionmode=1
ifcondition=measuresize2 = 0
iftrueaction=[!setoption filesize2 text "[measuredate2]"][!setOption icon2 MeterStyle "IconStyle | Folder2"][!setOption icon2B MeterStyle "IconStyle | Folder2"]
iffalseaction=[!setoption filesize2 text "[measuresize2:/1048576,2] Mb"][!setOption icon2 MeterStyle "IconStyle | File2"][!setOption icon2B MeterStyle "IconStyle | File2"]
group=fileviewplugin

[measuredate2]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=Filedate
datetype=created
index=2
group=fileviewplugin

[measurePath2]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=2
group=fileviewplugin

[measureName3]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filename
index=3
group=fileviewplugin
substitute="":"none"
ifmatch=none
ifmatchaction=[!hidemetergroup item3]
ifNotmatchAction=[!showmetergroup item3]

[measuresize3]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filesize
index=3
substitute="":"0"
ifconditionmode=1
ifcondition=measuresize3 = 0
iftrueaction=[!setoption filesize3 text "[measuredate3]"][!setOption icon3 MeterStyle "IconStyle | Folder3"][!setOption icon3B MeterStyle "IconStyle | Folder3"]
iffalseaction=[!setoption filesize3 text "[measuresize3:/1048576,2] Mb"][!setOption icon3 MeterStyle "IconStyle | File3"][!setOption icon3B MeterStyle "IconStyle | File3"]
group=fileviewplugin

[measuredate3]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=Filedate
datetype=created
index=3
group=fileviewplugin

[measurePath3]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=3
group=fileviewplugin

[measureName4]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filename
index=4
group=fileviewplugin
substitute="":"none"
ifmatch=none
ifmatchaction=[!hidemetergroup item4]
ifNotmatchAction=[!showmetergroup item4]

[measuresize4]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filesize
index=4
substitute="":"0"
ifconditionmode=1
ifcondition=measuresize4 = 0
iftrueaction=[!setoption filesize4 measurename "measuredate4"][!setoption filesize4 text "[measuredate4]"][!setOption icon4 MeterStyle "IconStyle | Folder4"][!setOption icon4B MeterStyle "IconStyle | Folder4"]
iffalseaction=[!setoption filesize4 text "[measuresize4:/1048576,2] Mb"][!setOption icon4 MeterStyle "IconStyle | File4"][!setOption icon4B MeterStyle "IconStyle | File4"]
group=fileviewplugin

[measuredate4]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=Filedate
datetype=created
index=4
group=fileviewplugin

[measurePath4]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=4
group=fileviewplugin

[measureName5]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filename
index=5
group=fileviewplugin
substitute="":"none"
ifmatch=none
ifmatchaction=[!hidemetergroup item5]
ifNotmatchAction=[!showmetergroup item5]

[measuresize5]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filesize
index=5
substitute="":"0"
ifconditionmode=1
ifcondition=measuresize5 = 0
iftrueaction=[!setoption filesize5 text "[measuredate5]"][!setOption icon5 MeterStyle "IconStyle | Folder5"][!setOption icon5B MeterStyle "IconStyle | Folder5"]
iffalseaction=[!setoption filesize5 text "[measuresize5:/1048576,2] Mb"][!setOption icon5 MeterStyle "IconStyle | File5"][!setOption icon5B MeterStyle "IconStyle | File5"]
group=fileviewplugin

[measuredate5]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=Filedate
datetype=created
index=5
group=fileviewplugin

[measurePath5]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=5
group=fileviewplugin

[measureName6]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filename
index=6
group=fileviewplugin
substitute="":"none"
ifmatch=none
ifmatchaction=[!hidemetergroup item6]
ifNotmatchAction=[!showmetergroup item6]

[measuresize6]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filesize
index=6
substitute="":"0"
ifconditionmode=1
ifcondition=measuresize6 = 0
iftrueaction=[!setoption filesize6 text "[measuredate6]"][!setOption icon6 MeterStyle "IconStyle | Folder6"][!setOption icon6B MeterStyle "IconStyle | Folder6"]
iffalseaction=[!setoption filesize6 text "[measuresize6:/1048576,2] Mb"][!setOption icon6 MeterStyle "IconStyle | File6"][!setOption icon6B MeterStyle "IconStyle | File6"]
group=fileviewplugin

[measuredate6]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=Filedate
datetype=created
index=6
group=fileviewplugin

[measurePath6]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=6
group=fileviewplugin

[measureName7]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filename
index=7
group=fileviewplugin
substitute="":"none"
ifmatch=none
ifmatchaction=[!hidemetergroup item7]
ifNotmatchAction=[!showmetergroup item7]

[measuresize7]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filesize
index=7
substitute="":"0"
ifconditionmode=1
ifcondition=measuresize7 = 0
iftrueaction=[!setoption filesize7 text "[measuredate7]"][!setOption icon7 MeterStyle "IconStyle | Folder7"][!setOption icon7B MeterStyle "IconStyle | Folder7"]
iffalseaction=[!setoption filesize7 text "[measuresize7:/1048576,2] Mb"][!setOption icon7 MeterStyle "IconStyle | File7"][!setOption icon7B MeterStyle "IconStyle | File7"]
group=fileviewplugin

[measuredate7]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=Filedate
datetype=created
index=7
group=fileviewplugin

[measurePath7]
measure=plugin
plugin=fileview
path=[measurerootpath]
type=filepath
index=7
group=fileviewplugin

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;MeterStyles~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[IconStyle]
solidcolor=0,0,0,1
maskimagepath=#@#images\mask
dynamicvariables=1
AntiAlias=1
h=80
w=80

[TextStyle]
solidcolor=0,0,0,1
dynamicvariables=1
clipstring=1
fontface=#fontface#
fontsize=#fontsize#
fontcolor=#fontcolor#
stringeffect=shadow
AntiAlias=1
