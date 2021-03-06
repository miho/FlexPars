Name:         flexpars  

%if %{defined suse_version}
BuildRequires: gcc-c++ cmake
#Requires:
%endif

%if %{defined fedora_version} || 0%{?rhel_version} || 0%{?centos_version}
BuildRequires: gcc-c++ cmake
#Requires:
%endif

%if %{defined mandriva_version}
BuildRequires: gcc-c++ cmake
#Requires:
%endif

License:      LGPL  
Group:        System/Libraries
Summary:      Small library to easily handle custom file formats 
BuildRoot:    %{_tmppath}/%{name}-%{version}-build  
URL:          http://github.com/miho/FlexPars
Version:      0.03
Release:      0
Source:       %name-%{version}.tar.gz
  
%description  
FlexPars is a small library to easily handle custom file formats.
   
   
   
Authors:  
--------  
     Michael Hoffer <info@michaelhoffer.de>  
   
%prep
%setup -q
  
%build 


%ifarch x86_64
  cmake -DCMAKE_INSTALL_PREFIX=$RPM_BUILD_ROOT/usr . -DLIB_SUFFIX=64
%else
  cmake -DCMAKE_INSTALL_PREFIX=$RPM_BUILD_ROOT/usr .
%endif

make  
  
%install  
make install

%clean
# clean up the hard disc after build
rm -rf $RPM_BUILD_ROOT
  
%files
%defattr(-,root,root)
%{_libdir}/flexpars/
%{_libdir}/flexpars/*
/usr/include/flexpars/
/usr/include/flexpars/*
