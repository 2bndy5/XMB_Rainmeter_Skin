function HSVtoRGB(Hue, Sat, Val)
	local h = Hue * 6
	local chroma = Val * Sat
	local mid = chroma * (1 - math.abs(h % 2 - 1))
	local Match = Val - chroma
--[[for Debug
	SKIN:Bang('!Log', "h = " .. h, 'Debug')
	SKIN:Bang('!Log', "Chroma = " .. chroma, 'Debug')
	SKIN:Bang('!Log', "mid = " .. mid, 'Debug')
	SKIN:Bang('!Log', "match = " .. Match, 'Debug')
]]--
	local rgb = {}
	if 0 <= h and h < 1 then
		rgb[1] = 255 * (chroma + Match)
		rgb[2] = 255 * (mid + Match)
		rgb[3] = 255 * (0 + Match)
	elseif 1 <= h and h < 2 then
		rgb[1] = 255 * (mid + Match)
		rgb[2] = 255 * (chroma + Match)
		rgb[3] = 255 * (0 + Match)
	elseif 2 <= h and h < 3 then
		rgb[1] = 255 * (0 + Match)
		rgb[2] = 255 * (chroma + Match)
		rgb[3] = 255 * (mid + Match)
	elseif 3 <= h and h < 4 then
		rgb[1] = 255 * (0 + Match)
		rgb[2] = 255 * (mid + Match)
		rgb[3] = 255 * (chroma + Match)
	elseif 4 <= h and h < 5 then
		rgb[1] = 255 * (mid + Match)
		rgb[2] = 255 * (0 + Match)
		rgb[3] = 255 * (chroma + Match)
	elseif 5 <= h and h <= 6 then
		rgb[1] = 255 * (chroma + Match)
		rgb[2] = 255 * (0 + Match)
		rgb[3] = 255 * (mid + Match)
	end--set rgb table
	for i = 1, 3, 1 do
		rgb[i] = math.floor(rgb[i] + 0.5)
	end
	return table.concat(rgb, ',')
end

function getHue(rgb)
	local hue
	if (2*rgb[1]-rgb[2]-rgb[3]) == 0 then
		hue = 0
	else
		hue = math.atan2((math.sqrt(3)*(rgb[2]-rgb[3])), (2*rgb[1]-rgb[2]-rgb[3]))
	end
	if hue < 0.0 then
		hue = hue + 6
	end
	return hue / 6
end

function Update()
	local color = SKIN:GetMeasure('GetBaseColor'):GetStringValue()
	local hex = ('%08X'):format(tonumber(color))
	local rgb = { tonumber(string.sub(hex, 3, 4), 16), tonumber(string.sub(hex, 5, 6), 16), tonumber(string.sub(hex, 7, 8), 16) }
--	SKIN:Bang('!Log', table.concat(rgb, ','), 'Debug')
	local Hue = getHue(rgb)
	SKIN:Bang('!SetVariable', 'palette1', HSVtoRGB(Hue, 0.3, 1))
	SKIN:Bang('!SetVariable', 'palette2', HSVtoRGB(Hue, 0.5, 1))
	SKIN:Bang('!SetVariable', 'palette3', HSVtoRGB(Hue, 0.65, 1))
	SKIN:Bang('!SetVariable', 'palette4', HSVtoRGB(Hue, 0.8, 0.8))
	SKIN:Bang('!SetVariable', 'palette5', HSVtoRGB(Hue, 1, 0.65))
	SKIN:Bang('!SetVariable', 'palette6', HSVtoRGB(Hue, 1, 0.5))
	SKIN:Bang('!SetVariable', 'palette7', HSVtoRGB(Hue, 1, 0.3))
end