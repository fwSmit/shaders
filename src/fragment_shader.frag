#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D texture;
uniform float time;
uniform vec2 u_resolution;
uniform sampler2D visible;

void main()
{
	// lookup the pixel in the texture
	vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

	// multiply it by the color
	float mult;
	vec2 st = gl_FragCoord.xy/u_resolution;
	if(mod(floor(gl_FragCoord.x), 30) == 0){
		mult = 1.0;
	}
	else{
		mult = 1.0;
	}
	gl_FragColor = vec4(1.0, 0.0, 0.0, mult);
}
