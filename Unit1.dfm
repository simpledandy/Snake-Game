object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Snake'
  ClientHeight = 715
  ClientWidth = 991
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  OnKeyDown = FormKeyDown
  TextHeight = 15
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 991
    Height = 105
    Align = alTop
    BevelInner = bvLowered
    BevelKind = bkSoft
    BevelWidth = 5
    BorderStyle = bsSingle
    Color = clGreen
    ParentBackground = False
    ShowCaption = False
    TabOrder = 0
    object SpeedButton1: TSpeedButton
      Left = 208
      Top = 13
      Width = 80
      Height = 38
      Caption = 'Start'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -26
      Font.Name = 'Segoe UI Semibold'
      Font.Style = []
      ParentFont = False
      OnClick = SpeedButton1Click
    end
    object Label1: TLabel
      Left = 328
      Top = 13
      Width = 77
      Height = 36
      Caption = 'Score: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'Sitka Subheading Semibold'
      Font.Style = []
      ParentFont = False
    end
    object ScoreLabel: TLabel
      Left = 411
      Top = 13
      Width = 22
      Height = 36
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'Sitka Subheading Semibold'
      Font.Style = []
      ParentFont = False
    end
    object movesLabel: TLabel
      Left = 539
      Top = 13
      Width = 15
      Height = 36
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'Sitka Subheading Semibold'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 456
      Top = 13
      Width = 87
      Height = 36
      Caption = 'Moves: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'Sitka Subheading Semibold'
      Font.Style = []
      ParentFont = False
    end
    object turnsLabel: TLabel
      Left = 667
      Top = 13
      Width = 15
      Height = 36
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'Sitka Subheading Semibold'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 584
      Top = 13
      Width = 81
      Height = 36
      Caption = 'Turns: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'Sitka Subheading Semibold'
      Font.Style = []
      ParentFont = False
    end
    object energyLabel: TLabel
      Left = 812
      Top = 13
      Width = 15
      Height = 36
      Caption = '0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'Sitka Subheading Semibold'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 720
      Top = 13
      Width = 94
      Height = 36
      Caption = 'Energy: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'Sitka Subheading Semibold'
      Font.Style = []
      ParentFont = False
    end
  end
  object FieldPanel: TPanel
    Left = 0
    Top = 105
    Width = 991
    Height = 610
    Align = alClient
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelWidth = 5
    BorderWidth = 5
    BorderStyle = bsSingle
    Color = clHighlight
    ParentBackground = False
    TabOrder = 1
    ExplicitTop = 73
    ExplicitHeight = 642
    DesignSize = (
      983
      602)
    object Food: TShape
      Left = 504
      Top = 184
      Width = 20
      Height = 20
      Anchors = [akRight, akBottom]
      Brush.Color = clAqua
      Shape = stCircle
      Visible = False
      ExplicitTop = 216
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 16
    Top = 552
  end
end
