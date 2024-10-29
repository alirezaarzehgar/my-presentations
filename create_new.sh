#!/usr/bin/env bash

pres_name="${1}"
if [ -z "$pres_name" ]; then
	echo "Missing presentation name"
	exit 1
fi

if [ -f "$pres_name" ]; then
	echo "$pres_name already exists in your presentations"
	exit 1
fi

mkdir "$pres_name"

cat << __EOF__ > "$pres_name/Makefile"
include ../builder.mk
__EOF__

cat << __EOF__ > "$pres_name/$pres_name.tex"
\documentclass{beamer}
\usetheme{Cuerna}

\author{Alireza Arzehgar}
\title{Presentation title}
\date{\today}

\begin{document}
	\begin{frame}[plain]
		\maketitle
	\end{frame}

	\begin{frame}
		\frametitle{Hello Presentation}
		\begin{itemize}
			\pause
			\item Item1
			\pause
			\item Item2
		\end{itemize}
	\end{frame}
\end{document}
__EOF__