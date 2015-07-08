object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Sample Size Pointer'
  ClientHeight = 337
  ClientWidth = 441
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
    Width = 441
    Height = 337
    Caption = 'Sample Pointer'
    Color = clBtnShadow
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    StyleElements = [seFont, seClient]
    object LabelAutor: TLabel
      Left = 322
      Top = 321
      Width = 114
      Height = 13
      Caption = 'Rafa'#322' Olszewski E4Y2S1'
    end
    object LabelUnit: TLabel
      Left = 403
      Top = 266
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
    object LabelColor: TLabel
      Left = 322
      Top = 24
      Width = 79
      Height = 18
      Caption = 'Pointer color:'
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
    object Label1: TLabel
      Left = 322
      Top = 67
      Width = 66
      Height = 18
      Caption = 'Brightness:'
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
    object Label2: TLabel
      Left = 359
      Top = 242
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
      Left = 352
      Top = 258
      Width = 49
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
      Left = 336
      Top = 285
      Width = 81
      Height = 25
      Caption = 'SET'
      TabOrder = 1
      OnClick = SetButtonClick
    end
    object TrackBar1: TTrackBar
      Left = 317
      Top = 40
      Width = 124
      Height = 45
      Max = 5
      PageSize = 1
      TabOrder = 2
      OnChange = TrackBar1Change
    end
    object ScrollBar1: TScrollBar
      Left = 322
      Top = 91
      Width = 111
      Height = 17
      BiDiMode = bdLeftToRight
      Ctl3D = False
      DoubleBuffered = False
      Max = 90
      PageSize = 0
      ParentBiDiMode = False
      ParentCtl3D = False
      ParentDoubleBuffered = False
      Position = 45
      TabOrder = 3
      TabStop = False
      OnChange = ScrollBar1Change
    end
  end
  object Timer1: TTimer
    Interval = 25
    OnTimer = Timer1Timer
    Left = 280
    Top = 272
  end
end
