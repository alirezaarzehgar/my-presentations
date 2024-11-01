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

mkdir -p "$pres_name/assets"

cat << __EOF__ > "$pres_name/Makefile"
include ../builder.mk
__EOF__

cat << __EOF__ > "$pres_name/$pres_name.tex"
\documentclass[xcolor={rgb}]{beamer}

\newcommand{\pitem}{\pause\item}
\usetheme{cfermat}

\author{Alireza Arzehgar}
\title{Title}
\date{\today}

\begin{document}
	\begin{frame}[plain]
		\titlepage
	\end{frame}

	\begin{frame}{Frame Title}
		\frametitle{Introduction}
		\begin{itemize}
			\pitem item1
			\pitem item2
		\end{itemize}
	\end{frame}

\end{document}
__EOF__