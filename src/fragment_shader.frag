#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D texture;
uniform float time;
uniform vec2 u_resolution;

void main()
{
	// lookup the pixel in the texture
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

	// multiply it by the color
	float mult = abs(sin(time));
	// gl_FragColor = abs(sin(time)) * gl_Color * pixel;
	vec2 st = gl_FragCoord.xy/u_resolution;
	gl_FragColor = vec4(st.x,st.y,0.0,noise1(10.));
}
