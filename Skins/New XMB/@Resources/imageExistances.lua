function Update()

  local FilePath = { SKIN:MakePathAbsolute(SELF:GetOption('File1')), SKIN:MakePathAbsolute(SELF:GetOption('File2')), SKIN:MakePathAbsolute(SELF:GetOption('File3')), SKIN:MakePathAbsolute(SELF:GetOption('File4')), SKIN:MakePathAbsolute(SELF:GetOption('File5')), SKIN:MakePathAbsolute(SELF:GetOption('File6')), SKIN:MakePathAbsolute(SELF:GetOption('File7')) }
  local GameCount = SKIN:GetMeasure('measuregameitems')
  local FileCount = GameCount:GetValue()

  for i = 1, FileCount,1 do
    local FoundFile = io.open(FilePath[i],'r')
    if not FoundFile then
      SKIN:Bang('!SetOption', i, 'MeterStyle', 'IconBG')
    else
      io.close(FoundFile)
      SKIN:Bang('!SetOption', i, 'MeterStyle', 'GameBanner')
    end
  end

  return FileCount
end