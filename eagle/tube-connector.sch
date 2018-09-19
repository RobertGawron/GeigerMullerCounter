<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.2.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="gm-con">
<description>GM connectors for STS-5 Geiger-Muler tube.</description>
<packages>
<package name="GM-CONNECTOR">
<pad name="P$1" x="0" y="0" drill="0.8" diameter="2.54" shape="octagon"/>
<pad name="P$2" x="0" y="-5" drill="0.8" diameter="2.54" shape="octagon"/>
<wire x1="-5" y1="5" x2="-5" y2="-10" width="0.127" layer="21"/>
<wire x1="-5" y1="-10" x2="5" y2="-10" width="0.127" layer="21"/>
<wire x1="5" y1="-10" x2="5" y2="5" width="0.127" layer="21"/>
<wire x1="5" y1="5" x2="-5" y2="5" width="0.127" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="GM-CONNECTOR">
<description>GM connectors for STS-5 Geiger-Muler tube.</description>
<pin name="P$1" x="0" y="0" length="middle"/>
<wire x1="5.08" y1="7.62" x2="5.08" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="5.08" x2="5.08" y2="0" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="5.08" y2="-2.54" width="0.254" layer="94"/>
<wire x1="5.08" y1="-2.54" x2="10.16" y2="-2.54" width="0.254" layer="94"/>
<wire x1="10.16" y1="-2.54" x2="10.16" y2="7.62" width="0.254" layer="94"/>
<wire x1="10.16" y1="7.62" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<pin name="P$2" x="0" y="5.08" length="middle"/>
<circle x="7.62" y="5.08" radius="1.27" width="0.254" layer="94"/>
<circle x="7.62" y="0" radius="1.27" width="0.254" layer="94"/>
<wire x1="5.08" y1="5.08" x2="6.35" y2="5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="0" x2="6.35" y2="0" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GM-CONNECTOR">
<description>GM connectors for STS-5 Geiger-Muler tube.</description>
<gates>
<gate name="G$1" symbol="GM-CONNECTOR" x="-2.54" y="0"/>
</gates>
<devices>
<device name="" package="GM-CONNECTOR">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="pinhead">
<description>&lt;b&gt;Pin Header Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="1X01">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<wire x1="-0.635" y1="1.27" x2="0.635" y2="1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="1.27" x2="1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="0.635" x2="1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-0.635" x2="0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="0.635" x2="-1.27" y2="-0.635" width="0.1524" layer="21"/>
<wire x1="-0.635" y1="1.27" x2="-1.27" y2="0.635" width="0.1524" layer="21"/>
<wire x1="-1.27" y1="-0.635" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="0.635" y1="-1.27" x2="-0.635" y2="-1.27" width="0.1524" layer="21"/>
<pad name="1" x="0" y="0" drill="1.016" shape="octagon"/>
<text x="-1.3462" y="1.8288" size="1.27" layer="25" ratio="10">&gt;NAME</text>
<text x="-1.27" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-0.254" y1="-0.254" x2="0.254" y2="0.254" layer="51"/>
</package>
</packages>
<symbols>
<symbol name="PINHD1">
<wire x1="-6.35" y1="-2.54" x2="1.27" y2="-2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="1.27" y2="2.54" width="0.4064" layer="94"/>
<wire x1="1.27" y1="2.54" x2="-6.35" y2="2.54" width="0.4064" layer="94"/>
<wire x1="-6.35" y1="2.54" x2="-6.35" y2="-2.54" width="0.4064" layer="94"/>
<text x="-6.35" y="3.175" size="1.778" layer="95">&gt;NAME</text>
<text x="-6.35" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="-2.54" y="0" visible="pad" length="short" direction="pas" function="dot"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="PINHD-1X1" prefix="JP" uservalue="yes">
<description>&lt;b&gt;PIN HEADER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PINHD1" x="0" y="0"/>
</gates>
<devices>
<device name="" package="1X01">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="gm-con" deviceset="GM-CONNECTOR" device=""/>
<part name="U$2" library="gm-con" deviceset="GM-CONNECTOR" device=""/>
<part name="JP2" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="U$3" library="gm-con" deviceset="GM-CONNECTOR" device=""/>
<part name="U$4" library="gm-con" deviceset="GM-CONNECTOR" device=""/>
<part name="U$5" library="gm-con" deviceset="GM-CONNECTOR" device=""/>
<part name="JP5" library="pinhead" deviceset="PINHD-1X1" device=""/>
<part name="U$6" library="gm-con" deviceset="GM-CONNECTOR" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="45.72" y="40.64"/>
<instance part="U$2" gate="G$1" x="45.72" y="25.4"/>
<instance part="JP2" gate="G$1" x="27.94" y="27.94" rot="MR0"/>
<instance part="U$3" gate="G$1" x="45.72" y="10.16"/>
<instance part="U$4" gate="G$1" x="78.74" y="40.64" rot="MR0"/>
<instance part="U$5" gate="G$1" x="78.74" y="25.4" rot="MR0"/>
<instance part="JP5" gate="G$1" x="96.52" y="27.94"/>
<instance part="U$6" gate="G$1" x="78.74" y="10.16" rot="MR0"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$3" class="0">
<segment>
<pinref part="U$3" gate="G$1" pin="P$2"/>
<wire x1="43.18" y1="15.24" x2="45.72" y2="15.24" width="0.1524" layer="91"/>
<wire x1="43.18" y1="15.24" x2="43.18" y2="12.7" width="0.1524" layer="91"/>
<pinref part="U$3" gate="G$1" pin="P$1"/>
<wire x1="43.18" y1="12.7" x2="43.18" y2="10.16" width="0.1524" layer="91"/>
<wire x1="43.18" y1="10.16" x2="45.72" y2="10.16" width="0.1524" layer="91"/>
<pinref part="JP2" gate="G$1" pin="1"/>
<wire x1="30.48" y1="27.94" x2="40.64" y2="27.94" width="0.1524" layer="91"/>
<wire x1="40.64" y1="27.94" x2="43.18" y2="27.94" width="0.1524" layer="91"/>
<wire x1="43.18" y1="27.94" x2="43.18" y2="30.48" width="0.1524" layer="91"/>
<pinref part="U$2" gate="G$1" pin="P$2"/>
<wire x1="43.18" y1="30.48" x2="45.72" y2="30.48" width="0.1524" layer="91"/>
<wire x1="43.18" y1="27.94" x2="43.18" y2="25.4" width="0.1524" layer="91"/>
<junction x="43.18" y="27.94"/>
<pinref part="U$2" gate="G$1" pin="P$1"/>
<wire x1="43.18" y1="25.4" x2="45.72" y2="25.4" width="0.1524" layer="91"/>
<wire x1="43.18" y1="12.7" x2="40.64" y2="12.7" width="0.1524" layer="91"/>
<wire x1="40.64" y1="12.7" x2="40.64" y2="27.94" width="0.1524" layer="91"/>
<junction x="43.18" y="12.7"/>
<junction x="40.64" y="27.94"/>
<wire x1="40.64" y1="27.94" x2="40.64" y2="43.18" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="P$1"/>
<wire x1="43.18" y1="40.64" x2="45.72" y2="40.64" width="0.1524" layer="91"/>
<wire x1="43.18" y1="40.64" x2="43.18" y2="43.18" width="0.1524" layer="91"/>
<pinref part="U$1" gate="G$1" pin="P$2"/>
<wire x1="43.18" y1="43.18" x2="43.18" y2="45.72" width="0.1524" layer="91"/>
<wire x1="43.18" y1="45.72" x2="45.72" y2="45.72" width="0.1524" layer="91"/>
<wire x1="40.64" y1="43.18" x2="43.18" y2="43.18" width="0.1524" layer="91"/>
<junction x="43.18" y="43.18"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="P$1"/>
<wire x1="81.28" y1="40.64" x2="78.74" y2="40.64" width="0.1524" layer="91"/>
<wire x1="81.28" y1="40.64" x2="81.28" y2="43.18" width="0.1524" layer="91"/>
<pinref part="U$4" gate="G$1" pin="P$2"/>
<wire x1="81.28" y1="43.18" x2="81.28" y2="45.72" width="0.1524" layer="91"/>
<wire x1="81.28" y1="45.72" x2="78.74" y2="45.72" width="0.1524" layer="91"/>
<pinref part="JP5" gate="G$1" pin="1"/>
<wire x1="93.98" y1="27.94" x2="83.82" y2="27.94" width="0.1524" layer="91"/>
<wire x1="83.82" y1="27.94" x2="81.28" y2="27.94" width="0.1524" layer="91"/>
<wire x1="81.28" y1="27.94" x2="81.28" y2="30.48" width="0.1524" layer="91"/>
<pinref part="U$5" gate="G$1" pin="P$2"/>
<wire x1="81.28" y1="30.48" x2="78.74" y2="30.48" width="0.1524" layer="91"/>
<wire x1="81.28" y1="27.94" x2="81.28" y2="25.4" width="0.1524" layer="91"/>
<junction x="81.28" y="27.94"/>
<pinref part="U$5" gate="G$1" pin="P$1"/>
<wire x1="81.28" y1="25.4" x2="78.74" y2="25.4" width="0.1524" layer="91"/>
<wire x1="81.28" y1="43.18" x2="83.82" y2="43.18" width="0.1524" layer="91"/>
<wire x1="83.82" y1="43.18" x2="83.82" y2="27.94" width="0.1524" layer="91"/>
<junction x="81.28" y="43.18"/>
<junction x="83.82" y="27.94"/>
<wire x1="83.82" y1="27.94" x2="83.82" y2="12.7" width="0.1524" layer="91"/>
<pinref part="U$6" gate="G$1" pin="P$2"/>
<wire x1="81.28" y1="15.24" x2="78.74" y2="15.24" width="0.1524" layer="91"/>
<wire x1="81.28" y1="15.24" x2="81.28" y2="12.7" width="0.1524" layer="91"/>
<pinref part="U$6" gate="G$1" pin="P$1"/>
<wire x1="81.28" y1="12.7" x2="81.28" y2="10.16" width="0.1524" layer="91"/>
<wire x1="81.28" y1="10.16" x2="78.74" y2="10.16" width="0.1524" layer="91"/>
<wire x1="83.82" y1="12.7" x2="81.28" y2="12.7" width="0.1524" layer="91"/>
<junction x="81.28" y="12.7"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
