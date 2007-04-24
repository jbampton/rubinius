class Actor
  def self.current
    Thread.current[:__current_actor__] ||= Actor.new(current_mailbox)
  end

  def self.current_mailbox
    Thread.current[:__current_mailbox__] ||= Mailbox.new
  end

  def self.receive(&prc)
    current_mailbox.receive(&prc)
  end

  def initialize(mailbox)
    @mailbox = mailbox
  end

  def send(value)
    @mailbox.send value
    self
  end
  alias :<< :send
end
