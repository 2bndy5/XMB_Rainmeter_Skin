function Initialize()
	variablesFile = SKIN:GetVariable('@') .. "variables.inc"
	settingsFile = SKIN:GetVariable('settingsPath') .. "rainmeter.ini"
	rootConfig = SKIN:GetVariable('RootConfig')
	--SKIN:Bang('!Log', variablesFile, 'Debug')
end

function Update()
--	capture = {home, settings, pictures, music, videos, games, internet, timeAndDate, weather, player, downloads}
	capture = {{false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}, {false, 0}}
	for line in io.lines(settingsFile) do
		local active = tonumber(string.match(line, "Active=(%d+)"))
		for i = 1, #capture, 1 do
			if active ~= nil then
				if active > 0 then 
					active = 1
				else 
					active = 0 
				end
				if capture[i][1] == true then
					capture[i][2] = active
					--SKIN:Bang('!Log', capture[i][2], 'Debug')
					capture[i][1] = false
				end
			end
		end
		if string.find(line, rootConfig .. '\\Home]') ~= nil then
			--SKIN:Bang('!Log', 'Home skin found', 'Debug')
			capture[1][1] = true
		end
		if string.find(line, rootConfig .. '\\Settings]') ~= nil then
			--SKIN:Bang('!Log', 'Settings skin found', 'Debug')
			capture[2][1] = true
		end
		if string.find(line, rootConfig .. '\\Pictures]') ~= nil then
			--SKIN:Bang('!Log', 'Pictures skin found', 'Debug')
			capture[3][1] = true
		end
		if string.find(line, rootConfig .. '\\Music]') ~= nil then
			--SKIN:Bang('!Log', 'Music skin found', 'Debug')
			capture[4][1] = true
		end
		if string.find(line, rootConfig .. '\\Videos]') ~= nil then
			--SKIN:Bang('!Log', 'Videos skin found', 'Debug')
			capture[5][1] = true
		end
		if string.find(line, rootConfig .. '\\Games]') ~= nil then
			--SKIN:Bang('!Log', 'Games skin found', 'Debug')
			capture[6][1] = true
		end
		if string.find(line, rootConfig .. '\\Internet]') ~= nil then
			--SKIN:Bang('!Log', 'Internet skin found', 'Debug')
			capture[7][1] = true
		end
		if string.find(line, rootConfig .. '\\Time and Date]') ~= nil then
			--SKIN:Bang('!Log', 'Time and Date skin found', 'Debug')
			capture[8][1] = true
		end
		if string.find(line, rootConfig .. '\\Home\\Vclouds Weather]') ~= nil then
			--SKIN:Bang('!Log', 'Weather skin found', 'Debug')
			capture[9][1] = true
		end
		if string.find(line, rootConfig .. '\\Music\\Player]') ~= nil then
			--SKIN:Bang('!Log', 'Player skin found', 'Debug')
			capture[10][1] = true
		end
		if string.find(line, rootConfig .. '\\Internet\\downloads]') ~= nil then
			--SKIN:Bang('!Log', 'Downloads skin found', 'Debug')
			capture[11][1] = true
		end
	end
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Home', capture[1][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Settings', capture[2][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Pictures', capture[3][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Music', capture[4][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Videos', capture[5][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Games', capture[6][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Internet', capture[7][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'TimeAndDate', capture[8][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Weather', capture[9][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Player', capture[10][2], variablesFile)
	SKIN:Bang('!WriteKeyValue', 'Variables', 'Downloads', capture[11][2], variablesFile)
	SKIN:Bang('!SetVariableGroup', 'Home', capture[1][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'Settings', capture[2][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'Pictures', capture[3][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'Music', capture[4][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'Videos', capture[5][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'Games', capture[6][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'Internet', capture[7][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'TimeAndDate', capture[8][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'Weather', capture[9][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'Player', capture[10][2], 'XMB')
	SKIN:Bang('!SetVariableGroup', 'Downloads', capture[11][2], 'XMB')

end