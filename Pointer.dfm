object Form1: TForm1
  Left = 0
  Top = 0
  AutoSize = True
  Caption = 'Sample Size Pointer'
  ClientHeight = 337
  ClientWidth = 425
  Color = clBtnShadow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox2: TGroupBox
    Left = 0
    Top = 0
    Width = 425
    Height = 337
    Caption = 'Sample Pointer'
    Color = clBtnShadow
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    StyleElements = [seFont, seClient]
    object LabelAutor: TLabel
      Left = 308
      Top = 324
      Width = 114
      Height = 13
      Caption = 'Rafa'#322' Olszewski E4Y2S1'
    end
    object LabelUnit: TLabel
      Left = 397
      Top = 50
      Width = 14
      Height = 13
      Hint = '0-200'#181'm'
      Caption = #181'm'
    end
    object Image1: TImage
      Left = 16
      Top = 24
      Width = 300
      Height = 300
    end
    object Label2: TLabel
      Left = 344
      Top = 24
      Width = 39
      Height = 18
      Caption = 'Value:'
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      GlowSize = 1
      ParentColor = False
      ParentFont = False
    end
    object EditValue: TEdit
      Left = 332
      Top = 42
      Width = 59
      Height = 21
      Hint = '0 - 200 '#956'm'
      MaxLength = 3
      NumbersOnly = True
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      Text = '0'
    end
    object SetButton: TButton
      Left = 332
      Top = 69
      Width = 59
      Height = 25
      Caption = 'SET'
      TabOrder = 1
      OnClick = SetButtonClick
    end
  end
  object Timer1: TTimer
    Interval = 25
    OnTimer = Timer1Timer
    Left = 280
    Top = 272
  end
end
