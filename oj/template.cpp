<%!
    import onlinejudge_template.generator.cplusplus as cplusplus
    import onlinejudge_template.generator.about as about
%>\
<%
    data['config']['indent'] = '  '
    data['config']['scanner'] = 'cin'
    data['config']['printer'] = 'cout'
%>\
#include <bits/stdc++.h>

#include "template.hpp"

${cplusplus.declare_constants(data)}
${cplusplus.return_type(data)} solve(${cplusplus.formal_arguments(data)}) {
	// TODO: edit here
}

// generated by ${about.title} ${about.version} (${about.url})
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
${cplusplus.read_input(data)}
	auto ${cplusplus.return_value(data)} = solve(${cplusplus.actual_arguments(data)});
${cplusplus.write_output(data)}
	return 0;
}
