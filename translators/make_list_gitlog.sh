#!/bin/bash

mkdir -p list
base=$PWD/lxqt
outdir=$base/../list

cd $base
ts=`find . -name *_*$1.ts`
rm -f $outdir/gitlog_$1.list

# rm XXXXXX

for fp in $ts ; do
  cd $base
  dir=${fp%/*}
  fn=${fp##*/}

  lang=$fp
  lang=${lang#*_}
  lang=${lang%.ts}
  cd $dir
  echo "gitlog: $fn"
  echo "F:$fn" >> $outdir/gitlog_$lang.list
  git log --use-mailmap --no-merges --pretty=format:"%H" $fn | xargs -n1 git log -1 --numstat --shortstat --pretty=format:"H:%H%ns:%s%nA:%aN %aE%na:%an %ae%nD:%ai" >> $outdir/gitlog_$lang.list
done
