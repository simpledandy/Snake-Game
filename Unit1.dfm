object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Snake'
  ClientHeight = 761
  ClientWidth = 1070
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnKeyDown = FormKeyDown
  TextHeight = 15
  object FieldPanel: TPanel
    Left = 0
    Top = 105
    Width = 1070
    Height = 656
    Align = alClient
    BevelInner = bvSpace
    BevelKind = bkSoft
    BevelWidth = 5
    BorderWidth = 5
    BorderStyle = bsSingle
    Color = clHighlight
    ParentBackground = False
    ShowCaption = False
    TabOrder = 0
    ExplicitWidth = 1068
    ExplicitHeight = 648
    DesignSize = (
      1062
      648)
    object Food: TShape
      Left = 583
      Top = 230
      Width = 20
      Height = 20
      Anchors = [akRight, akBottom]
      Brush.Color = clAqua
      Shape = stCircle
      Visible = False
      ExplicitLeft = 504
      ExplicitTop = 216
    end
  end
  object TopPanel: TPanel
    Left = 0
    Top = 0
    Width = 1070
    Height = 105
    Align = alTop
    BevelInner = bvLowered
    BevelKind = bkSoft
    BevelWidth = 5
    BorderStyle = bsSingle
    Color = clGreen
    ParentBackground = False
    ShowCaption = False
    TabOrder = 1
    ExplicitWidth = 1068
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
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 8
    Top = 113
  end
end
