public class ValueNode implements Expression {
	private double value;

	public ValueNode(double value) {
		this.value = value;
	}

	@Override
	public double eval() {
		return value;
	}

	@Override
	public String expression() {
		return String.format("%.2f", value);
	}

}
