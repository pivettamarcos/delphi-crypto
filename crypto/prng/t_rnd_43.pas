{Simple test for MT19937 unit, we Aug.2005}

program t_rnd_43;

{$i STD.INC}

{$ifdef win32}
  {$ifndef VirtualPascal}
    {$apptype console}
  {$endif}
{$endif}

{$ifndef FPC}
  {$N+}
{$endif}

uses
  {$ifdef WINCRT}
    wincrt,
  {$endif}
  hrtimer, mt19937;

const
  LOOPS  = 10;

var
  ctx: mt19937_ctx;


procedure mt19937_generate(var ctx: mt19937_ctx);
  {-generate next 625 result values}
var
  i: integer;
begin
  for i:=0 to 623 do mt19937_next(ctx);
end;


{---------------------------------------------------------------------------}
function GenerateCycles: longint;
var
  i: integer;
  cyc0, cyc1, cyc2: comp;
  t1,t2,c1,c2: longint;
begin
  c1 := MaxLongint;
  c2 := MaxLongint;
  for i:=1 to LOOPS do begin
    ReadTSC(cyc0);
    mt19937_generate(ctx);
    ReadTSC(cyc1);
    mt19937_generate(ctx);
    mt19937_generate(ctx);
    mt19937_generate(ctx);
    mt19937_generate(ctx);
    mt19937_generate(ctx);
    ReadTSC(cyc2);
    t2 := round(cyc2-cyc1);
    t1 := round(cyc1-cyc0);
    if t1<c1 then c1 := t1;
    if t2<c2 then c2 := t2;
  end;
  GenerateCycles := (c2-c1+1) shr 2;
end;


var
  CBlk: longint;
  CPB : double;
begin
  writeln('Test for MT19937 unit  (c) 2005 W.Ehrhardt');
  writeln('MT19937 selftest: ',mt19937_selftest);
  fillchar(ctx, sizeof(ctx),0);
  mt19937_init(ctx, 0);
  CBlK := GenerateCycles;
  CPB  := CBlk/2496.0;
  writeln('   CPU Frequency: ', CPUFrequency/1E6:1:1);
  writeln('        Generate: ', CBlk);
  writeln('     Cycles/Byte: ', CPB:1:1);
  writeln('            MB/s: ', CPUFrequency/CPB/1E6:1:3);
end.
