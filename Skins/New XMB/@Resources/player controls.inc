
[mTitle]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=#PlayerName#
PlayerType=Title

[mAlbum]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=Album

[mArtist]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=Artist

[mplayButton]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=STATE
Substitute="0":"#@#\images\play.png","1":"#@#\images\pause.png","2":"#@#\images\play.png"

[mVolume]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=VOLUME
ifEqualValue=0
ifEqualAction=[!setOption volumepercentage text "Mute"][!redraw]
ifAboveValue=0
ifAboveAction=[!setOption volumepercentage text "%1%"][!redraw]

[mTitleShuffle]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=SHUFFLE
Substitute="0":"#@#\images\shuffleoff.png","1":"#@#\images\shuffleon.png"

[mTitleRepeat]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=REPEAT
Substitute="0":"#@#\images\repeatoff.png","1":"#@#\images\repeaton.png"

[mTrackProgress]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=PROGRESS

[mTrackTime]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=DURATION
disableleadingzero=1

[mTrackPosition]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=POSITION
disableleadingzero=1

[measureplayerstatus]
measure=plugin
plugin=nowplaying
PlayerName=[mTitle]
playertype=status
ifequalvalue=1
ifequalaction=[!setoption play meterstyle playstyle]
ifbelowvalue=1
ifbelowaction=[!setoption play meterstyle openstyle]

[mbusyonoff]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[mTitle]
PlayerType=STATE
ifabovevalue=0
ifaboveaction=[!setoption Stop meterstyle Stopstyle]
ifequalvalue=0
ifequalaction=[!setoption Stop meterstyle closestyle]


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;MeterStyles~~~~~~~~~~~~~~~~~~~~~~~~
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

[TextStyle]
dynamicvariables=1
clipstring=1
fontface=#fontface#
fontsize=#fontsize#
fontcolor=#fontcolor#
stringeffect=shadow
AntiAlias=1
