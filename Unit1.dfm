object Form1: TForm1
  Left = 512
  Top = 158
  Width = 706
  Height = 436
  Caption = 'SQLite Demo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 552
    Height = 389
    Align = alClient
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 552
    Top = 0
    Width = 136
    Height = 389
    Align = alRight
    TabOrder = 1
    object btnOpen: TButton
      Left = 8
      Top = 8
      Width = 121
      Height = 33
      Caption = 'Open'
      TabOrder = 0
      OnClick = btnOpenClick
    end
    object btnQuery: TButton
      Left = 8
      Top = 56
      Width = 121
      Height = 33
      Caption = 'Query'
      TabOrder = 1
      OnClick = btnQueryClick
    end
    object btnClose: TButton
      Left = 8
      Top = 344
      Width = 121
      Height = 33
      Caption = 'Close'
      TabOrder = 2
      OnClick = btnCloseClick
    end
    object btnSQL: TButton
      Left = 7
      Top = 104
      Width = 121
      Height = 33
      Caption = 'SQL Test'
      TabOrder = 3
      OnClick = btnSQLClick
    end
  end
end
