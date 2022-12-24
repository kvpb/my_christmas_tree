<!-- Let the good times roll, baby! -->

<p align="center"><img src="https://rawcdn.githack.com/kvpb/my_christmas_tree/50032b04850b9feea777e44877bbfe759c55fef9/img.gif"><br>
<i>Merry Christmas!</i> &#x1F384;</p>

# My Christmas Tree

![C](https://img.shields.io/badge/-C-1B75B3?style=flat&logo=c&logoColor=a8b9cc) ![macOS](https://img.shields.io/badge/-macOS-FFF?style=flat&logo=apple&logoColor=A7A9AC) ![Linux](https://img.shields.io/badge/-Linux-0094FF?style=flat&logo=linux&logoColor=003778) ![platform](https://gistcdn.githack.com/kvpb/ed57eb3a03f2b5338fbede97e7cf296b/raw/ea6556bb04f592433023533ddbd931cc7d23e92b/apple-F6F6F6D5E1ED1E72F21AD5FD-madeona-1AD5FD1E72F2-mac-F6F6F6D5E1ED.svg) ![platform](https://gistcdn.githack.com/kvpb/ed57eb3a03f2b5338fbede97e7cf296b/raw/ea6556bb04f592433023533ddbd931cc7d23e92b/ubuntu-F6F6F6D5E1ED1E72F21AD5FD-madeona-1AD5FD1E72F2-linuxbox-F6F6F6D5E1ED.svg)

> Create a program which can be run in the terminal that display a Christmas Tree.
>
> Size will be given as the first parameter of the program.
>
> Usage: ./my_christmas_tree <size></size>
>
> **Example 00**:
> ```
> $>./my_christmas_tree 0
> $>
> ```
>
> **Example 01**:
> ```
> $>./my_christmas_tree 1
>    *
>   ***
>  *****
> ******* 
>    |
> 
> ```
>
> **Example 02**:
> ```
> $>./my_christmas_tree 5
>                    *
>                   ***
>                  *****
>                 *******
>                  *****
>                 *******
>                *********
>               ***********
>              *************
>               ***********
>              *************
>             ***************
>            *****************
>           *******************
>          *********************
>            *****************
>           *******************
>          *********************
>         ***********************
>        *************************
>       ***************************
>      *****************************
>        *************************
>       ***************************
>      *****************************
>     *******************************
>    *********************************
>   ***********************************
>  *************************************
> ***************************************
>                  |||||
>                  |||||
>                  |||||
>                  |||||
>                  |||||
> $>
> ```
>
> From docode you can download the qwasar_my_christmas_tree by executing this command:
>
> ```
> curl -s https://storage.googleapis.com/qwasar-public/qwasar_my_christmas_tree.tgz | tar zxvf - -C ./
> ```

&nbsp;&nbsp;[Qwasar Silicon Valley](https://upskill.us.qwasar.io/projects/my_christmas_tree)

<!--1.	Enter the following commands in a command-line interface.-->

## Setup

This software is an UNIX command-line program written in [C](https://www.open-std.org/jtc1/sc22/wg14/). It as such requires an [UNIX](http://opengroup.org/unix)-certified or [POSIX](http://get.posixcertified.ieee.org/)-compliant operating system or operating environment, e.g. [macOS](https://www.apple.com/macos) with [Command Line Tools](https://developer.apple.com/library/archive/technotes/tn2339/_index.html), [FreeBSD](https://www.freebsd.org/), [Arch Linux](https://archlinux.org/), [CRUX](https://crux.nu/) or [Alpine Linux](https://alpinelinux.org/), a command-line shell, e.g. [BASH](https://www.gnu.org/software/bash/), [ZSH](https://www.zsh.org/) or [TCSH](https://www.tcsh.org/), and a standard C optimizing compiler, e.g. [GNU C Compiler](https://gcc.gnu.org/) or [CLANG](https://clang.llvm.org/). The user may set it up and use it from a command-line interface in a graphical user interface via a terminal emulator, e.g. [iTerm2](https://iterm2.com), [Terminator](https://gnome-terminator.org) or [the integrated terminal of Visual Studio Code](https://code.visualstudio.com/docs/editor/integrated-terminal). These instructions assume the user knows how to use an UNIX shell<!-- such as [BASH](https://www.gnu.org/software/bash/) or [ZSH](https://www.zsh.org/)--> in a POSIX-compliant development and runtime environment<!-- like [macOS](https://www.apple.com/macos/) or [a Linux-based operating system](https://www.linux.org/pages/download/)-->.

We now declare a few SH functions and variables for the sake of brevity. The user of course can forgo this and do it all by themselves manually.

```sh
pathname()
{
	printf "$(cd "$(dirname "${1}")" && pwd -P)/$(basename "${1}")"'\n'
}

URL="https://git.us.qwasar.io/my_christmas_tree_81526_qrbmic/my_christmas_tree"
dir="${URL%/*}" && dir="${dir##*/}" # optionally.
repo="${URL##*/}"
progname="${repo}"
bin="$(pathname)${dir}/${repo}/${progname}"
i=0
n=$[RANDOM%23]
```

**The user should avoid setting this software up from a critical location in the file system, e.g. `/` or the parent directory of other software.** We advise doing so from a dedicated, throwaway directory. The user therefore optionally can:

```sh
mkdir ${dir} # preferably from ${HOME}.
cd ${dir}
```

Once the user has obtained the sources of this software, they may proceed to compile them. They should do thus:

```sh
git clone https://github.com/kvpb/my_christmas_tree #${URL}
cd ${repo}
# preferably from ${dir}/.
gcc -Wall -Werror -Wextra -o ${progname} ex00/my_christmas_tree.c # from ${repo}/.
```

The executable file at this point should be in `${repo}/`. <!--The user should be able to run it tel quel.-->

<!--2.	Then test it--- just compare its behavior to the requirements of the subject:-->

## Use

The user now may test the software. They simply have to compare it to Qwasar Silicon Valley's Gaetan Juvin's ELF executable. They could do thus:

```sh
for (( ; i < n; ))
do
	${bin} ${i}
	i=$(( i + 1 ))
done
# from ${repo}/ any directory in the file system.
```

The user then should examine how the program behaves. Using [Qwasar Silicon Valley's My Christmas Tree](https://upskill.us.qwasar.io/projects/my_christmas_tree) and the [DIFF](https://www.freebsd.org/cgi/man.cgi?diff) command-line utility and [redirecting the standard output with BASH](https://www.gnu.org/software/bash/manual/html_node/Redirections.html) may help them achieve this. If the user can access Qwasar Silicon Valley's DoCode, they can do thus from it:

```sh
curl -s https://storage.googleapis.com/qwasar-public/qwasar_my_christmas_tree.tgz | tar zxvf - -C ./ # from the landing directory on DoCode.
for (( ; i < n; ))
do
	diff --suppress-common-lines -y <(./qwasar_my_christmas_tree ${i}) <(./my_christmas_tree ${i})
	i=$(( i + 1 ))
done
```

***

<p align="center"><i>Made at <img alt="Qwasar Silicon Valley Logo" src="https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png" width="12px"> <a href="https://qwasar.io">Qwasar Silicon Valley</a> by</i><br>
<a href="http://kvpb.co"><img src="https://gistcdn.githack.com/kvpb/c80594e9079e857c55c36dec49a1a2d7/raw/eec54d5821dc092ad910635141c4e4feebf07565/kvpbssymbol.svg"></a><br>
<b>Karl V. P. B. `<code>kvpb</code>`<br>AKA&nbsp;&nbsp;Karl <!--&lsquo;T.G.&rsquo;--> Thomas George <!--<span style="font-variant: small-caps;">-->West<!--</span>--> `<code>ktgw</code>`</b><br>
<a href="https://www.linkedin.com/in/karlbertin">LinkedIn</a>&nbsp;&nbsp;<a href="https://github.com/kvpb">GitHub</a><br>
<br>
<br>
<br>
<img src="https://gistcdn.githack.com/kvpb/f5f75716dd024cc48f8dc28176c0b642/raw/e5344bebf926b378faeb208724ae97f4e06639ca/kvpbsesrbrating.svg"></p>
