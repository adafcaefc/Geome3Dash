if exist "about.md" del "about.md"
copy "..\README.md" "about.md"
7z\7z.exe a -tzip "C:\Program Files (x86)\Steam\steamapps\common\Geometry Dash\geode\mods\rainixgd.geome3dash.geode" -mx1 -x!7z -x!rainixgd.geome3dash.exp -x!rainixgd.geome3dash.lib -x!*.bat
"C:\Program Files (x86)\Steam\steamapps\common\Geometry Dash\GeometryDash.exe"
