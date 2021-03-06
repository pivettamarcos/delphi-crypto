{******************************************************************************}
{*  TDialogButtons.int.inc                                                    *}
{*  Revolutionary Confederation of Anarcho Syndicalists                       *}
{*  Written by: black.rabbit 2011                                             *}
{******************************************************************************}
{ ������ ������ ����������� ���� }
{$M+}
    CDialogButtons = class of TDialogButtons;
    PDialogButtons = ^TDialogButtons;
    TDialogButtons = class (TItems)
    private
        f_Owner: TWinControl;          { �������� ������ }
        f_ImageList: TCustomImageList; { ����� ���������� ��� ������ }
        f_OnClick: TNotifyEvent;       { �������� �� ��������� }
    protected
        function Check (anItem: Pointer) : Boolean; override;
        function Check (anItem: TDialogButton) : Boolean; overload; virtual;
    protected
        function GetItemAt (anIndex: Integer) : TDialogButton; overload; virtual;
        function GetItemOf (aName: String) : TDialogButton; overload; virtual;
        procedure SetItemAt (anIndex: Integer; anItem: TDialogButton); overload; virtual;
        procedure SetItemOf (aName: String; anItem: TDialogButton); overload; virtual;
    protected
        procedure SetOwner (const anOwner: TWinControl); virtual;
        procedure SetImageList (const anImageList: TCustomImageList); virtual;
        procedure SetOnClick (const anOnClick: TNotifyEvent); virtual;
    public
        constructor Create (const anOwner: TWinControl;
                            const anImageList: TCustomImageList;
                            const anOnClick: TNotifyEvent;
                            anArgs: array of const); overload; virtual;
        constructor Create (const anOwner: TWinControl;
                            const anImageList: TCustomImageList;
                            const anOnClick: TNotifyEvent); overload; virtual;
        destructor Destroy; override;
    protected
        class function ItemClassType : CDialogButton; virtual;
    public
        function Add (anItem: TDialogButton) : Integer; overload; virtual;
        function Add (const anOwner: TWinControl;
                      const anImageList: TCustomImageList;
                      const anOnClick: TNotifyEvent;
                      anArgs: array of const) : Integer; overload; virtual;
        function Add (anArgs: array of const) : Integer; overload; virtual;
        procedure FreeItem (anIndex: Integer); override;
    public
        property Owner: TWinControl read f_Owner write SetOwner;
        property ImageList: TCustomImageList read f_ImageList write SetImageList;
        property OnClick: TNotifyEvent read f_OnClick write SetOnClick;
        property ItemAt [anIndex: Integer]: TDialogButton read GetItemAt write SetItemAt;
        property ItemOf [aName: String]: TDialogButton read GetItemOf write SetItemOf;
    end;
{$M-}
