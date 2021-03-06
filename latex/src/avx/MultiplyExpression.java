public class MultiplyExpression extends BinaryExpression {

	public MultiplyExpression(Expression left, Expression right) {
		super(left, right);
	}

	@Override
	public double eval() {
		return left.eval() * right.eval();
	}

	@Override
	public String expression() {
		return String
				.format("(%s * %s)", left.expression(), right.expression());
	}

}
